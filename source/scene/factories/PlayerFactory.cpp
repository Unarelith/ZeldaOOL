/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 22:02:26
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"
#include "PlayerFactory.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void mapCollisions(SceneObject &player);

SceneObject PlayerFactory::create(float x, float y) {
	SceneObject object;
	object.setComponent<PositionComponent>(x, y, 16, 16);
	
	MovementComponent *movementComponent = object.setComponent<MovementComponent>(new GamePadMovement);
	movementComponent->collisionHandlers.push_back(&mapCollisions);
	
	SpriteComponent *spriteComponent = object.setComponent<SpriteComponent>("characters-link", 16, 16);
	spriteComponent->sprite.addAnimation({4, 0}, 110);
	spriteComponent->sprite.addAnimation({5, 1}, 110);
	spriteComponent->sprite.addAnimation({6, 2}, 110);
	spriteComponent->sprite.addAnimation({7, 3}, 110);
	spriteComponent->isAnimated = true;
	
	return object;
}

#include "Map.hpp"

void mapCollisions(SceneObject &object) {
	PositionComponent *positionComponent = object.getComponent<PositionComponent>();
	MovementComponent *movementComponent = object.getComponent<MovementComponent>();
	
	// Pixel-perfect link hitbox for each 4 directions
	u8 collisionMatrix[4][4] = {
		{ 4, 8, 4,13},
		{12, 8,12,13},
		{ 5, 5,10, 5},
		{ 5,15,10,15}
	};
	
	// Iterate through the directions
	for(u8 i = 0 ; i < 4 ; i++) {
		bool test;
		
		// Test the velocity vector for each direction
		if(i == 0) {
			test = (movementComponent->vx < 0);
		}
		else if(i == 1) {
			test = (movementComponent->vx > 0);
		}
		else if(i == 2) {
			test = (movementComponent->vy < 0);
		}
		else if(i == 3) {
			test = (movementComponent->vy > 0);
		}
		
		if(test
		&& (!Map::currentMap->passable(positionComponent->x + collisionMatrix[i][0], positionComponent->y + collisionMatrix[i][1])
		||  !Map::currentMap->passable(positionComponent->x + collisionMatrix[i][2], positionComponent->y + collisionMatrix[i][3]))) {
			if(i < 2)	movementComponent->vx = 0;
			else		movementComponent->vy = 0;
			
			// If the player is looking at the wall, block it
			if((i == 0 && positionComponent->direction == Direction::Right)
			|| (i == 1 && positionComponent->direction == Direction::Left)
			|| (i == 2 && positionComponent->direction == Direction::Up)
			|| (i == 3 && positionComponent->direction == Direction::Down)) {
				movementComponent->isBlocked = true;
			}
			
			// Test collisions with tile borders in order to shift the player
			if( Map::currentMap->passable(positionComponent->x + collisionMatrix[i][2], positionComponent->y + collisionMatrix[i][3])
			&& !Map::currentMap->passable(positionComponent->x + collisionMatrix[i][0], positionComponent->y + collisionMatrix[i][1])) {
				if(i < 2 && movementComponent->vy == 0) {
					movementComponent->vy = 1;
				}
				else if(movementComponent->vx == 0) {
					movementComponent->vx = 1;
				}
				
				movementComponent->isBlocked = false;
			}
			
			if( Map::currentMap->passable(positionComponent->x + collisionMatrix[i][0], positionComponent->y + collisionMatrix[i][1])
			&& !Map::currentMap->passable(positionComponent->x + collisionMatrix[i][2], positionComponent->y + collisionMatrix[i][3])) {
				if(i < 2 && movementComponent->vy == 0) {
					movementComponent->vy = -1;
				}
				else if(movementComponent->vx == 0) {
					movementComponent->vx = -1;
				}
				
				movementComponent->isBlocked = false;
			}
		}
	}
}

