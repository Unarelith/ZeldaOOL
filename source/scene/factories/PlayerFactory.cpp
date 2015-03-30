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
#include "Sprite.hpp"
#include "TransitionState.hpp"

#include "CollisionComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "StateComponent.hpp"

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
	
	auto *spriteComponent = object.setComponent<Sprite>("characters-link", 16, 16);
	
	// Walking
	spriteComponent->addAnimation({4, 0}, 110);
	spriteComponent->addAnimation({5, 1}, 110);
	spriteComponent->addAnimation({6, 2}, 110);
	spriteComponent->addAnimation({7, 3}, 110);
	
	// Pushing
	spriteComponent->addAnimation({ 8, 12}, 90);
	spriteComponent->addAnimation({ 9, 13}, 90);
	spriteComponent->addAnimation({10, 14}, 90);
	spriteComponent->addAnimation({11, 15}, 90);
	
	// Using sword
	spriteComponent->addAnimation({16, 20, 20, 20, 20, 20, 20, 20}, 40);
	spriteComponent->addAnimation({17, 21, 21, 21, 21, 21, 21, 21}, 40);
	spriteComponent->addAnimation({18, 22, 22, 22, 22, 22, 22, 22}, 40);
	spriteComponent->addAnimation({19, 23, 23, 23, 23, 23, 23, 23}, 40);
	
	// SpinAttack
	spriteComponent->addAnimation({20, 20, 22, 22, 23, 23, 21, 21}, 50);
	
	auto *stateComponent = object.setComponent<StateComponent>();
	stateComponent->addState("Standing", 0, false);
	stateComponent->addState("Moving", 0);
	stateComponent->addState("Pushing", 4);
	stateComponent->setCurrentState("Standing");
	
	return object;
}

void mapCollisions(SceneObject &object) {
	auto *movementComponent = object.getComponent<MovementComponent>();
	auto *positionComponent = object.getComponent<PositionComponent>();
	auto *stateComponent = object.getComponent<StateComponent>();
	
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
		
		// Iterate through directions
		for(u8 i = 0 ; i < 4 ; i++) {
			bool velocityTest = false;
			bool directionTest = false;
			
			if(i == 0) {
				velocityTest = movementComponent->vx < 0;
				directionTest = positionComponent->direction == Direction::Left;
			}
			else if(i == 1) {
				velocityTest = movementComponent->vx > 0;
				directionTest = positionComponent->direction == Direction::Right;;
			}
			else if(i == 2) {
				velocityTest = movementComponent->vy < 0;
				directionTest = positionComponent->direction == Direction::Up;
			}
			else if(i == 3) {
				velocityTest = movementComponent->vy > 0;
				directionTest = positionComponent->direction == Direction::Down;
			}
			
			bool firstPosPassable  = Map::currentMap->passable(positionComponent->x + collisionMatrix[i][0], positionComponent->y + collisionMatrix[i][1]);
			bool secondPosPassable = Map::currentMap->passable(positionComponent->x + collisionMatrix[i][2], positionComponent->y + collisionMatrix[i][3]);
			
			if(velocityTest && (!firstPosPassable || !secondPosPassable)) {
				if(i < 2)	movementComponent->vx = 0;
				else		movementComponent->vy = 0;
				
				// If the player is looking at the wall, block it
				if(directionTest) movementComponent->isBlocked = true;
				
				// Test collisions with tile borders in order to shift the player
				if(!firstPosPassable && secondPosPassable) {
					if(i < 2 && movementComponent->vy == 0) {
						movementComponent->vy = 1;
					}
					else if(movementComponent->vx == 0) {
						movementComponent->vx = 1;
					}
					
					movementComponent->isBlocked = false;
				}
				
				if(firstPosPassable && !secondPosPassable) {
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
		
		if(movementComponent->isBlocked) {
			stateComponent->setCurrentState("Pushing");
		}
		else if(movementComponent->isMoving) {
			stateComponent->setCurrentState("Moving");
		} else {
			stateComponent->setCurrentState("Standing");
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

