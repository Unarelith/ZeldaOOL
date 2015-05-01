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
#include "Movable.hpp"

void GamePadMovement::process(Movable &movable) {
	float vx = 0;
	float vy = 0;
	
	if(GamePad::isKeyPressed(GameKey::Left)) {
		vx = -1;
		
		if(!GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Up)
		&& !GamePad::isKeyPressed(GameKey::Down)) {
			movable.setDirection(Movable::Direction::Left);
		}
	}
	else if(GamePad::isKeyPressed(GameKey::Right)) {
		vx = 1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Up)
		&& !GamePad::isKeyPressed(GameKey::Down)) {
			movable.setDirection(Movable::Direction::Right);
		}
	}
	
	if(GamePad::isKeyPressed(GameKey::Up)) {
		vy = -1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Down)) {
			movable.setDirection(Movable::Direction::Up);
		}
	}
	else if(GamePad::isKeyPressed(GameKey::Down)) {
		vy = 1;
		
		if(!GamePad::isKeyPressed(GameKey::Left)
		&& !GamePad::isKeyPressed(GameKey::Right)
		&& !GamePad::isKeyPressed(GameKey::Up)) {
			movable.setDirection(Movable::Direction::Down);
		}
	}
	
	if((GamePad::isKeyPressed(GameKey::Left) || GamePad::isKeyPressed(GameKey::Right))
	&& (GamePad::isKeyPressed(GameKey::Up) || GamePad::isKeyPressed(GameKey::Down))) {
		vx /= 1.4;
		vy /= 1.4;
	}
	
	movable.setVelocity(vx, vy);
}

