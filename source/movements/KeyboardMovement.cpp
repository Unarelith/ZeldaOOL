/*
 * =====================================================================================
 *
 *       Filename:  KeyboardMovement.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 19:09:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GamePad.hpp"
#include "KeyboardMovement.hpp"
#include "Movable.hpp"

KeyboardMovement::KeyboardMovement() {
}

KeyboardMovement::~KeyboardMovement() {
}

void KeyboardMovement::doMovement(Movable &movable) {
	float vx = 0;
	float vy = 0;
	
	if(GamePad::getInstance().isKeyPressed(GamePad::Left)) {
		vx = -1;
		
		if(!GamePad::getInstance().isKeyPressed(GamePad::Right)
		&& !GamePad::getInstance().isKeyPressed(GamePad::Up)
		&& !GamePad::getInstance().isKeyPressed(GamePad::Down)) {
			movable.setDirection(Movable::Direction::Left);
		}
	}
	else if(GamePad::getInstance().isKeyPressed(GamePad::Right)) {
		vx = 1;
		
		if(!GamePad::getInstance().isKeyPressed(GamePad::Left)
		&& !GamePad::getInstance().isKeyPressed(GamePad::Up)
		&& !GamePad::getInstance().isKeyPressed(GamePad::Down)) {
			movable.setDirection(Movable::Direction::Right);
		}
	}
	
	if(GamePad::getInstance().isKeyPressed(GamePad::Up)) {
		vy = -1;
		
		if(!GamePad::getInstance().isKeyPressed(GamePad::Left)
		&& !GamePad::getInstance().isKeyPressed(GamePad::Right)
		&& !GamePad::getInstance().isKeyPressed(GamePad::Down)) {
			movable.setDirection(Movable::Direction::Up);
		}
	}
	else if(GamePad::getInstance().isKeyPressed(GamePad::Down)) {
		vy = 1;
		
		if(!GamePad::getInstance().isKeyPressed(GamePad::Left)
		&& !GamePad::getInstance().isKeyPressed(GamePad::Right)
		&& !GamePad::getInstance().isKeyPressed(GamePad::Up)) {
			movable.setDirection(Movable::Direction::Down);
		}
	}
	
	if((GamePad::getInstance().isKeyPressed(GamePad::Left) || GamePad::getInstance().isKeyPressed(GamePad::Right))
	&& (GamePad::getInstance().isKeyPressed(GamePad::Up) || GamePad::getInstance().isKeyPressed(GamePad::Down))) {
		vx /= 1.4;
		vy /= 1.4;
	}
	
	movable.setVelocity(vx, vy);
}

