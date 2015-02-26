/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:55:04
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "GamePad.hpp"
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

void GamePadMovement::process(SceneObject &object) {
	auto *movementComponent = object.getComponent<MovementComponent>();
	auto *positionComponent = object.getComponent<PositionComponent>();
	
	if(GamePad::isKeyPressed(GameKey::Left)) {
		movementComponent->vx = -1;
		
		if(!GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Up)
		&& !GamePad::isKeyPressed(GameKey::Down)) {
			positionComponent->direction = Direction::Left;
		}
	}
	else if(GamePad::isKeyPressed(GameKey::Right)) {
		movementComponent->vx = 1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Up)
		&& !GamePad::isKeyPressed(GameKey::Down)) {
			positionComponent->direction = Direction::Right;
		}
	}
	
	if(GamePad::isKeyPressed(GameKey::Up)) {
		movementComponent->vy = -1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Down)) {
			positionComponent->direction = Direction::Up;
		}
	}
	else if(GamePad::isKeyPressed(GameKey::Down)) {
		movementComponent->vy = 1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Up)) {
			positionComponent->direction = Direction::Down;
		}
	}
	
	if((GamePad::isKeyPressed(GameKey::Left) || GamePad::isKeyPressed(GameKey::Right))
	&& (GamePad::isKeyPressed(GameKey::Up)   || GamePad::isKeyPressed(GameKey::Down))) {
		movementComponent->vx /= 1.4;
		movementComponent->vy /= 1.4;
	}
}

