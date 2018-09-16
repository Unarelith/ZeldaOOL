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
#include "Map.hpp"
#include "PlayerBehaviour.hpp"
#include "PlayerFactory.hpp"
#include "SceneObjectList.hpp"
#include "ScrollingTransition.hpp"
#include "TilesInfos.hpp"
#include "TransitionState.hpp"

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
	SceneObject player;
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
		Map::currentMap->scene().checkCollisionsFor(player);
	});

	auto &effectsComponent = player.set<EffectsComponent>();
	effectsComponent.addEffect("grass", "animations-grassEffect", 16, 16);
	effectsComponent.addEffect("lowWater", "animations-lowWaterEffect", 16, 16);

	auto &spriteComponent = player.set<SpriteComponent>("characters-link", 16, 16);

	std::vector<std::vector<Vector2i>> usingSwordPosition = {
		{{ 0,  0}, { 0,  0}, { 0,  3}, { 0,  3}, { 0,  3}, { 0,  3}, { 0,  0}, { 0,  0}},
		{{ 0,  0}, { 0,  0}, { 4,  0}, { 4,  0}, { 4,  0}, { 4,  0}, { 0,  0}, { 0,  0}},
		{{ 0,  0}, { 0,  0}, {-4,  0}, {-4,  0}, {-4,  0}, {-4,  0}, { 0,  0}, { 0,  0}},
		{{ 0,  0}, { 0,  0}, { 0, -3}, { 0, -3}, { 0, -3}, { 0, -3}, { 0,  0}, { 0,  0}}
	};

	std::vector<Vector2i> swordSpinAttackPosition = {
		{ 0,  3}, { 0,  3},
		{-4,  0}, {-4,  0},
		{ 0, -3}, { 0, -3},
		{ 4,  0}, { 4,  0}
	};

	// Walking
	spriteComponent.sprite.addAnimation({{4, 0}, 110});
	spriteComponent.sprite.addAnimation({{5, 1}, 110});
	spriteComponent.sprite.addAnimation({{6, 2}, 110});
	spriteComponent.sprite.addAnimation({{7, 3}, 110});

	// Pushing
	spriteComponent.sprite.addAnimation({{ 8, 12}, 90});
	spriteComponent.sprite.addAnimation({{ 9, 13}, 90});
	spriteComponent.sprite.addAnimation({{10, 14}, 90});
	spriteComponent.sprite.addAnimation({{11, 15}, 90});

	// Using sword
	spriteComponent.sprite.addAnimation({{16, 20, 20, 20, 20, 20, 20, 20}, usingSwordPosition[0], 45});
	spriteComponent.sprite.addAnimation({{17, 21, 21, 21, 21, 21, 21, 21}, usingSwordPosition[1], 45});
	spriteComponent.sprite.addAnimation({{18, 22, 22, 22, 22, 22, 22, 22}, usingSwordPosition[2], 45});
	spriteComponent.sprite.addAnimation({{19, 23, 23, 23, 23, 23, 23, 23}, usingSwordPosition[3], 45});

	// Spin attack
	spriteComponent.sprite.addAnimation({{20, 20, 22, 22, 23, 23, 21, 21}, swordSpinAttackPosition, 50});

	// Lift action
	spriteComponent.sprite.addAnimation({{24, 28}, 150});
	spriteComponent.sprite.addAnimation({{25, 29}, 150});
	spriteComponent.sprite.addAnimation({{26, 30}, 150});
	spriteComponent.sprite.addAnimation({{27, 31}, 150});

	spriteComponent.sprite.addAnimation({{32, 28}, 90});
	spriteComponent.sprite.addAnimation({{33, 29}, 90});
	spriteComponent.sprite.addAnimation({{34, 30}, 90});
	spriteComponent.sprite.addAnimation({{35, 31}, 90});

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

		bool firstPosPassable  = Map::currentMap->passable(position.x + collisionMatrix[i][0], position.y + collisionMatrix[i][1]);
		bool secondPosPassable = Map::currentMap->passable(position.x + collisionMatrix[i][2], position.y + collisionMatrix[i][3]);

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
		return (Map::currentMap->isTile(position.x + 6, position.y + 11, tile)
			&&  Map::currentMap->isTile(position.x + 7, position.y + 11, tile)
			&&  Map::currentMap->isTile(position.x + 6, position.y + 12, tile)
			&&  Map::currentMap->isTile(position.x + 7, position.y + 12, tile));
	};

	if(onTile(TilesInfos::TileType::SlowingTile)) {
		movement.v /= 2;
	}

	if(onTile(TilesInfos::TileType::LowGrassTile)) {
		movement.v /= 4;
		movement.v *= 3;
	}

	effects.enableIf("grass", onTile(TilesInfos::TileType::LowGrassTile));

	if(position.x < -3) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(&ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingLeft);
	}
	else if(position.x + 13 > Map::currentMap->width() * 16) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(&ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingRight);
	}
	else if(position.y < -1) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(&ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingUp);
	}
	else if(position.y + 15 > Map::currentMap->height() * 16) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(&ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingDown);
	}
}

