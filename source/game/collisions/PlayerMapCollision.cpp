/*
 * =====================================================================================
 *
 *       Filename:  PlayerMapCollision.cpp
 *
 *    Description:
 *
 *        Created:  25/09/2018 16:44:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "PlayerMapCollision.hpp"
#include "ScrollingTransition.hpp"
#include "TilesInfos.hpp"
#include "TransitionState.hpp"
#include "World.hpp"

#include "EffectsComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

void PlayerMapCollision::update(SceneObject &player) {
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


