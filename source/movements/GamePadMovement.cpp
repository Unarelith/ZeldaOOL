/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:55:04
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GamePad.hpp"
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"

void GamePadMovement::process(SceneObject &object) {
	MovementComponent *movementComponent = object.getComponent<MovementComponent>();
	
	if(GamePad::isKeyPressed(GameKey::Left)) {
		movementComponent->vx = -1;
		
		if(!GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Up)
		&& !GamePad::isKeyPressed(GameKey::Down)) {
			//movable.setDirection(Movable::Direction::Left);
		}
	}
	else if(GamePad::isKeyPressed(GameKey::Right)) {
		movementComponent->vx = 1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Up)
		&& !GamePad::isKeyPressed(GameKey::Down)) {
			//movable.setDirection(Movable::Direction::Right);
		}
	}
	
	if(GamePad::isKeyPressed(GameKey::Up)) {
		movementComponent->vy = -1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Down)) {
			//movable.setDirection(Movable::Direction::Up);
		}
	}
	else if(GamePad::isKeyPressed(GameKey::Down)) {
		movementComponent->vy = 1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Up)) {
			//movable.setDirection(Movable::Direction::Down);
		}
	}
	
	if((GamePad::isKeyPressed(GameKey::Left) || GamePad::isKeyPressed(GameKey::Right))
	&& (GamePad::isKeyPressed(GameKey::Up)   || GamePad::isKeyPressed(GameKey::Down))) {
		movementComponent->vx /= 1.4;
		movementComponent->vy /= 1.4;
	}
}

