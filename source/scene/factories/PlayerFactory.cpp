/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 22:02:26
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePadMovement.hpp"
#include "Map.hpp"
#include "PlayerFactory.hpp"
#include "ScrollingTransition.hpp"
#include "TransitionState.hpp"

#include "CollisionComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void mapCollisions(SceneObject &player);

SceneObject PlayerFactory::create(float x, float y) {
	SceneObject object;
	object.setComponent<MovementComponent>(new GamePadMovement);
	
	auto *positionComponent = object.setComponent<PositionComponent>(x, y, 16, 16);
	positionComponent->hitbox.reset(4, 5, 8, 10);
	
	auto *collisionComponent = object.setComponent<CollisionComponent>();
	collisionComponent->addChecker(&mapCollisions);
	collisionComponent->addChecker([](SceneObject &object) {
		Map::currentMap->scene().checkCollisionsFor(object);
	});
	
	auto *spriteComponent = object.setComponent<SpriteComponent>("characters-link", 16, 16);
	spriteComponent->sprite.addAnimation({4, 0}, 110);
	spriteComponent->sprite.addAnimation({5, 1}, 110);
	spriteComponent->sprite.addAnimation({6, 2}, 110);
	spriteComponent->sprite.addAnimation({7, 3}, 110);
	spriteComponent->isAnimated = true;
	
	return object;
}

void mapCollisions(SceneObject &object) {
	auto *positionComponent = object.getComponent<PositionComponent>();
	auto *movementComponent = object.getComponent<MovementComponent>();
	
	if(positionComponent && movementComponent) {
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
		
		if(positionComponent->x < -3) {
			auto &state = ApplicationStateStack::getInstance().push<TransitionState>(ApplicationStateStack::getInstance().top());
			state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingLeft);
		}
		else if(positionComponent->x + 13 > Map::currentMap->width() * 16) {
			auto &state = ApplicationStateStack::getInstance().push<TransitionState>(ApplicationStateStack::getInstance().top());
			state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingRight);
		}
		else if(positionComponent->y < -1) {
			auto &state = ApplicationStateStack::getInstance().push<TransitionState>(ApplicationStateStack::getInstance().top());
			state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingUp);
		}
		else if(positionComponent->y + 15 > Map::currentMap->height() * 16) {
			auto &state = ApplicationStateStack::getInstance().push<TransitionState>(ApplicationStateStack::getInstance().top());
			state.setTransition<ScrollingTransition>(ScrollingTransition::Mode::ScrollingDown);
		}
	}
}

