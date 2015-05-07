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
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

SceneObject PlayerFactory::create(float x, float y) {
	SceneObject player;
	player.set<BehaviourComponent>(new PlayerBehaviour);
	player.set<MovementComponent>(new GamePadMovement);
	player.set<SceneObjectList>();
	
	auto &positionComponent = player.set<PositionComponent>(x, y, 16, 16);
	positionComponent.direction = Direction::Down;
	positionComponent.hitbox.reset(4, 5, 8, 10);
	
	auto &collisionComponent = player.set<CollisionComponent>();
	collisionComponent.addChecker(&PlayerFactory::mapCollisions);
	collisionComponent.addChecker([](SceneObject &player) {
		Map::currentMap->scene().checkCollisionsFor(player);
	});
	
	auto &spriteComponent = player.set<SpriteComponent>("characters-link", 16, 16);
	
	std::vector<std::vector<std::pair<s16, s16>>> usingSwordPosition = {
		{{ 0,  0}, { 0,  0}, { 0,  3}, { 0,  3}, { 0,  3}, { 0,  3}, { 0,  0}, { 0,  0}},
		{{ 0,  0}, { 0,  0}, { 4,  0}, { 4,  0}, { 4,  0}, { 4,  0}, { 0,  0}, { 0,  0}},
		{{ 0,  0}, { 0,  0}, {-4,  0}, {-4,  0}, {-4,  0}, {-4,  0}, { 0,  0}, { 0,  0}},
		{{ 0,  0}, { 0,  0}, { 0, -3}, { 0, -3}, { 0, -3}, { 0, -3}, { 0,  0}, { 0,  0}}
	};
	
	std::vector<std::pair<s16, s16>> swordSpinAttackPosition = {
		{ 0,  3}, { 0,  3},
		{-4,  0}, {-4,  0},
		{ 0, -3}, { 0, -3},
		{ 4,  0}, { 4,  0}
	};
	
	// Walking
	spriteComponent.sprite.addAnimation({4, 0}, 110);
	spriteComponent.sprite.addAnimation({5, 1}, 110);
	spriteComponent.sprite.addAnimation({6, 2}, 110);
	spriteComponent.sprite.addAnimation({7, 3}, 110);
	
	// Pushing
	spriteComponent.sprite.addAnimation({ 8, 12}, 90);
	spriteComponent.sprite.addAnimation({ 9, 13}, 90);
	spriteComponent.sprite.addAnimation({10, 14}, 90);
	spriteComponent.sprite.addAnimation({11, 15}, 90);
	
	// Using sword
	spriteComponent.sprite.addAnimation({16, 20, 20, 20, 20, 20, 20, 20}, usingSwordPosition[0], 40);
	spriteComponent.sprite.addAnimation({17, 21, 21, 21, 21, 21, 21, 21}, usingSwordPosition[1], 40);
	spriteComponent.sprite.addAnimation({18, 22, 22, 22, 22, 22, 22, 22}, usingSwordPosition[2], 40);
	spriteComponent.sprite.addAnimation({19, 23, 23, 23, 23, 23, 23, 23}, usingSwordPosition[3], 40);
	
	// Spin attack
	spriteComponent.sprite.addAnimation({20, 20, 22, 22, 23, 23, 21, 21}, swordSpinAttackPosition, 50);
	
	return player;
}

void PlayerFactory::mapCollisions(SceneObject &player) {
	auto &movement = player.get<MovementComponent>();
	auto &position = player.get<PositionComponent>();
	
	// Pixel-perfect link hitbox for each 4 directions
	// Two hitboxes:
	// H: (4, 8, 8, 5)
	// V: (5, 5, 5, 10)
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
			velocityTest = movement.vx < 0;
			directionTest = position.direction == Direction::Left;
		}
		else if(i == 1) {
			velocityTest = movement.vx > 0;
			directionTest = position.direction == Direction::Right;;
		}
		else if(i == 2) {
			velocityTest = movement.vy < 0;
			directionTest = position.direction == Direction::Up;
		}
		else if(i == 3) {
			velocityTest = movement.vy > 0;
			directionTest = position.direction == Direction::Down;
		}
		
		bool firstPosPassable  = Map::currentMap->passable(position.x + collisionMatrix[i][0], position.y + collisionMatrix[i][1]);
		bool secondPosPassable = Map::currentMap->passable(position.x + collisionMatrix[i][2], position.y + collisionMatrix[i][3]);
		
		if(velocityTest && (!firstPosPassable || !secondPosPassable)) {
			if(i < 2)	movement.vx = 0;
			else		movement.vy = 0;
			
			// If the player is looking at the wall, block it
			if(directionTest) movement.isBlocked = true;
			
			// Test collisions with tile borders in order to shift the player
			if(!firstPosPassable && secondPosPassable) {
				if(i < 2 && movement.vy == 0) {
					movement.vy = 1;
				}
				else if(movement.vx == 0) {
					movement.vx = 1;
				}
				
				movement.isBlocked = false;
			}
			
			if(firstPosPassable && !secondPosPassable) {
				if(i < 2 && movement.vy == 0) {
					movement.vy = -1;
				}
				else if(movement.vx == 0) {
					movement.vx = -1;
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
		movement.vx /= 2;
		movement.vy /= 2;
	}
	
	if(onTile(TilesInfos::TileType::LowGrassTile)) {
		movement.vx /= 4;
		movement.vx *= 3;
		
		movement.vy /= 4;
		movement.vy *= 3;
	}
	
	if(position.x < -3) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingLeft);
	}
	else if(position.x + 13 > Map::currentMap->width() * 16) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingRight);
	}
	else if(position.y < -1) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingUp);
	}
	else if(position.y + 15 > Map::currentMap->height() * 16) {
		auto &state = ApplicationStateStack::getInstance().push<TransitionState>(ApplicationStateStack::getInstance().top());
		state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingDown);
	}
}

