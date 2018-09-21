/*
 * =====================================================================================
 *
 *       Filename:  PlayerMapCollisionAction.cpp
 *
 *    Description:
 *
 *        Created:  20/04/2018 21:07:57
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "EffectsComponent.hpp"
#include "MovementComponent.hpp"
#include "PlayerMapCollisionAction.hpp"
#include "PositionComponent.hpp"
#include "ScrollingTransition.hpp"
#include "TileMap.hpp"
#include "TilesInfos.hpp"
#include "TransitionState.hpp"

// Pixel-perfect link hitbox for each 4 directions
// Two hitboxes:
// H: (4, 8, 8, 5)  | (4;8) -> (12;13)
// V: (5, 5, 5, 10) | (5;5) -> (10;15)
static u8 collisionMatrix[4][4] = {
	{ 4, 8, 4,13},
	{12, 8,12,13},
	{ 5, 5,10, 5},
	{ 5,15,10,15}
};

// FIXME: IMPROVE THIS FUNCTION A LOT
void PlayerMapCollisionAction::operator()(SceneObject &player, SceneObject &object, bool) {
	if (object.type() == "tilemap") {
		auto &movement = player.get<MovementComponent>();
		auto &position = player.get<PositionComponent>();
		auto &effects = player.get<EffectsComponent>();

		const TileMap &tileMap = object.get<TileMap>();

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

			const Tile &firstTile  = tileMap.getTileInfo(position.x + collisionMatrix[i][0], position.y + collisionMatrix[i][1]);
			const Tile &secondTile = tileMap.getTileInfo(position.x + collisionMatrix[i][2], position.y + collisionMatrix[i][3]);

			// FIXME: Map rework: Use TilesInfos for accurate collisions
			bool firstPosObstacle  = (firstTile.type() == 1);
			bool secondPosObstacle = (secondTile.type() == 1);

			if(velocityTest && (firstPosObstacle || secondPosObstacle)) {
				if(i < 2)   movement.v.x = 0;
				else        movement.v.y = 0;

				// If the player is looking at the wall, block it
				if(directionTest) movement.isBlocked = true;

				// Test collisions with tile borders in order to shift the player
				if(firstPosObstacle && !secondPosObstacle) {
					if(i < 2 && movement.v.y == 0) {
						movement.v.y = 1;
					}
					else if(movement.v.x == 0) {
						movement.v.x = 1;
					}

					movement.isBlocked = false;
				}

				if(!firstPosObstacle && secondPosObstacle) {
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

		auto onTile = [&](u16 tile) {
			return (tileMap.getTileInfo(position.x + 6, position.y + 11).type() == tile
				&&  tileMap.getTileInfo(position.x + 7, position.y + 11).type() == tile
				&&  tileMap.getTileInfo(position.x + 6, position.y + 12).type() == tile
				&&  tileMap.getTileInfo(position.x + 7, position.y + 12).type() == tile);
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
			auto &state = ApplicationStateStack::getInstance().push<TransitionState>(player, &ApplicationStateStack::getInstance().top());
			state.setTransition<ScrollingTransition>(player, object, ScrollingTransition::Mode::ScrollingLeft);
		}
		else if(position.x + 13 > tileMap.width() * 16) {
			auto &state = ApplicationStateStack::getInstance().push<TransitionState>(player, &ApplicationStateStack::getInstance().top());
			state.setTransition<ScrollingTransition>(player, object, ScrollingTransition::Mode::ScrollingRight);
		}
		else if(position.y < -1) {
			auto &state = ApplicationStateStack::getInstance().push<TransitionState>(player, &ApplicationStateStack::getInstance().top());
			state.setTransition<ScrollingTransition>(player, object, ScrollingTransition::Mode::ScrollingUp);
		}
		else if(position.y + 15 > tileMap.height() * 16) {
			auto &state = ApplicationStateStack::getInstance().push<TransitionState>(player, &ApplicationStateStack::getInstance().top());
			state.setTransition<ScrollingTransition>(player, object, ScrollingTransition::Mode::ScrollingDown);
		}
	}
}

