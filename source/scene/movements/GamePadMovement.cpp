/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.hpp
 *
 *    Description:  
 *
 *        Created:  18/01/2015 02:00:46
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
	auto &movementComponent = object.get<MovementComponent>();
	auto &positionComponent = object.get<PositionComponent>();
	
	if(GamePad::isKeyPressed(GameKey::Left)) {
		movementComponent.v.x = -1;
		
		if(!GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Up)
		&& !GamePad::isKeyPressed(GameKey::Down)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Left;
		}
	}
	else if(GamePad::isKeyPressed(GameKey::Right)) {
		movementComponent.v.x = 1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Up)
		&& !GamePad::isKeyPressed(GameKey::Down)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Right;
		}
	}
	
	if(GamePad::isKeyPressed(GameKey::Up)) {
		movementComponent.v.y = -1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Down)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Up;
		}
	}
	else if(GamePad::isKeyPressed(GameKey::Down)) {
		movementComponent.v.y = 1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Up)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Down;
		}
	}
	
	if((GamePad::isKeyPressed(GameKey::Left) || GamePad::isKeyPressed(GameKey::Right))
	&& (GamePad::isKeyPressed(GameKey::Up)   || GamePad::isKeyPressed(GameKey::Down))) {
		movementComponent.v /= 1.4;
	}
}

