/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 00:24:59
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePadMovement.hpp"
#include "PlayerBehaviour.hpp"
#include "PlayerFactory.hpp"
#include "ResourceHandler.hpp"
#include "SceneObjectList.hpp"
#include "ScrollingTransition.hpp"
#include "TilesInfos.hpp"
#include "TransitionState.hpp"
#include "World.hpp"

#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "EffectsComponent.hpp"
#include "HealthComponent.hpp"
#include "HitboxComponent.hpp"
#include "InventoryComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

SceneObject PlayerFactory::create(float x, float y) {
	SceneObject player{"Link", "Player"};
	player.set<SpriteComponent>(ResourceHandler::getInstance().get<SpriteComponent>("sprite-characters-link"));
	player.set<BehaviourComponent>(new PlayerBehaviour);
	player.set<HealthComponent>(13 * 4, 11 * 4);
	player.set<MovementComponent>(new GamePadMovement);
	player.set<SceneObjectList>();

	auto &positionComponent = player.set<PositionComponent>(x, y, 16, 16);
	positionComponent.direction = Direction::Down;

	auto &hitboxComponent = player.set<HitboxComponent>();
	hitboxComponent.addHitbox(4, 5, 8, 10);

	auto &collisionComponent = player.set<CollisionComponent>();
	collisionComponent.addChecker(&PlayerFactory::mapCollisions);
	collisionComponent.addChecker([](SceneObject &player) {
		World::getInstance().currentMap()->scene().checkCollisionsFor(player);
	});

	auto &effectsComponent = player.set<EffectsComponent>();
	effectsComponent.addEffect("grass", "animations-grassEffect", 16, 16);
	Sprite &effect = effectsComponent.addEffect("lowWater", "animations-lowWaterEffect", 16, 16, {0, 8});
	effect.addAnimation({{0, 1, 2}, 150});

	auto &inventoryComponent = player.set<InventoryComponent>();
	inventoryComponent.addWeapon("swordL1");
	inventoryComponent.addWeapon("strengthL1");
	inventoryComponent.equipWeapon(0, 0, GameKey::A);
	inventoryComponent.equipWeapon(0, 1, GameKey::B);

	return player;
}

void PlayerFactory::mapCollisions(SceneObject &player) {
	auto &movement = player.get<MovementComponent>();
	auto &position = player.get<PositionComponent>();
	auto &effects = player.get<EffectsComponent>();

	// Pixel-perfect link hitbox for each 4 directions
	// Two hitboxes:
	// H: (4, 8, 8, 5)  | (4;8) -> (12;13)
	// V: (5, 5, 5, 10) | (5;5) -> (10;15)
	u8 collisionMatrix[4][4] = {
		{ 4, 8, 4,13},
		{12, 8,12,13},
		{ 5, 5,10, 5},
		{ 5,15,10,15}
	};

	// Iterate through directions
	for(u8 i = 0 ; i < 4 ; i++) {
		bool velocityTest = false;
		bool directionTest = false;

		if(i == 0) {
			velocityTest = movement.v.x < 0;
			directionTest = position.direction == Direction::Left;
		}
		else if(i == 1) {
			velocityTest = movement.v.x > 0;
			directionTest = position.direction == Direction::Right;;
		}
		else if(i == 2) {
			velocityTest = movement.v.y < 0;
			directionTest = position.direction == Direction::Up;
		}
		else if(i == 3) {
			velocityTest = movement.v.y > 0;
			directionTest = position.direction == Direction::Down;
		}

		bool firstPosPassable  = World::getInstance().currentMap()->passable(position.x + collisionMatrix[i][0], position.y + collisionMatrix[i][1]);
		bool secondPosPassable = World::getInstance().currentMap()->passable(position.x + collisionMatrix[i][2], position.y + collisionMatrix[i][3]);

		if(velocityTest && (!firstPosPassable || !secondPosPassable)) {
			if(i < 2)	movement.v.x = 0;
			else		movement.v.y = 0;

			// If the player is looking at the wall, block it
			if(directionTest) movement.isBlocked = true;

			// Test collisions with tile borders in order to shift the player
			if(!firstPosPassable && secondPosPassable) {
				if(i < 2 && movement.v.y == 0) {
					movement.v.y = 1;
				}
				else if(movement.v.x == 0) {
					movement.v.x = 1;
				}

				movement.isBlocked = false;
			}

			if(firstPosPassable && !secondPosPassable) {
				if(i < 2 && movement.v.y == 0) {
					movement.v.y = -1;
				}
				else if(movement.v.x == 0) {
					movement.v.x = -1;
				}

				movement.isBlocked = false;
			}
		}
	}

	auto onTile = [position](u16 tile) {
		return (World::getInstance().currentMap()->isTile(position.x + 6, position.y + 11, tile)
			&&  World::getInstance().currentMap()->isTile(position.x + 7, position.y + 11, tile)
			&&  World::getInstance().currentMap()->isTile(position.x + 6, position.y + 12, tile)
			&&  World::getInstance().currentMap()->isTile(position.x + 7, position.y + 12, tile));
	};

	if(onTile(TilesInfos::TileType::SlowingTile)) {
		movement.v /= 2;
	}

	if(onTile(TilesInfos::TileType::LowGrassTile)) {
		movement.v /= 4;
		movement.v *= 3;
	}

	effects.enableIf("grass", onTile(TilesInfos::TileType::LowGrassTile));
	effects.enableIf("lowWater", onTile(TilesInfos::TileType::LowWaterTile));

	if(position.x < -3) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(&ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingLeft);
	}
	else if(position.x + 13 > World::getInstance().currentMap()->width() * 16) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(&ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingRight);
	}
	else if(position.y < -1) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(&ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingUp);
	}
	else if(position.y + 15 > World::getInstance().currentMap()->height() * 16) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(&ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingDown);
	}
}

