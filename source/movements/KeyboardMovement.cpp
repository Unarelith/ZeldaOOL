/*
 * =====================================================================================
 *
 *       Filename:  KeyboardMovement.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/01/2015 02:00:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "KeyboardMovement.hpp"
#include "Movable.hpp"

void KeyboardMovement::doMovement(Movable &movable) {
	float vx = 0;
	float vy = 0;
	
	if(Keyboard::isKeyPressed(Keyboard::Left)) {
		vx = -1;
		
		if(!Keyboard::isKeyPressed(Keyboard::Right)
		&& !Keyboard::isKeyPressed(Keyboard::Up)
		&& !Keyboard::isKeyPressed(Keyboard::Down)) {
			movable.setDirection(Movable::Direction::Left);
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Right)) {
		vx = 1;
		
		if(!Keyboard::isKeyPressed(Keyboard::Left)
		&& !Keyboard::isKeyPressed(Keyboard::Up)
		&& !Keyboard::isKeyPressed(Keyboard::Down)) {
			movable.setDirection(Movable::Direction::Right);
		}
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Up)) {
		vy = -1;
		
		if(!Keyboard::isKeyPressed(Keyboard::Left)
		&& !Keyboard::isKeyPressed(Keyboard::Right)
		&& !Keyboard::isKeyPressed(Keyboard::Down)) {
			movable.setDirection(Movable::Direction::Up);
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Down)) {
		vy = 1;
		
		if(!Keyboard::isKeyPressed(Keyboard::Left)
		&& !Keyboard::isKeyPressed(Keyboard::Right)
		&& !Keyboard::isKeyPressed(Keyboard::Up)) {
			movable.setDirection(Movable::Direction::Down);
		}
	}
	
	if((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right))
	&& (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down))) {
		vx /= 1.4;
		vy /= 1.4;
	}
	
	movable.setVelocity(vx, vy);
}

