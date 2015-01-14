/*
 * =====================================================================================
 *
 *       Filename:  MovingState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:25:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "MovingState.hpp"
#include "StandingState.hpp"
#include "Weapon.hpp"

MovingState::MovingState() {
	m_directionLocked = false;
}

MovingState::~MovingState() {
}

void MovingState::move() {
	if(Keyboard::isKeyPressed(Keyboard::Left)) {
		m_character.setVX(-1);
		
		if(!Keyboard::isKeyPressed(Keyboard::Up)
		&& !Keyboard::isKeyPressed(Keyboard::Down)) {
			if(!m_directionLocked) m_character.setDirection(Player::Direction::Left);
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Right)) {
		m_character.setVX(1);
		
		if(!Keyboard::isKeyPressed(Keyboard::Up)
		&& !Keyboard::isKeyPressed(Keyboard::Down)) {
			if(!m_directionLocked) m_character.setDirection(Player::Direction::Right);
		}
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Up)) {
		m_character.setVY(-1);
		
		if(!Keyboard::isKeyPressed(Keyboard::Left)
		&& !Keyboard::isKeyPressed(Keyboard::Right)) {
			if(!m_directionLocked) m_character.setDirection(Player::Direction::Up);
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Down)) {
		m_character.setVY(1);
		
		if(!Keyboard::isKeyPressed(Keyboard::Left)
		&& !Keyboard::isKeyPressed(Keyboard::Right)) {
			if(!m_directionLocked) m_character.setDirection(Player::Direction::Down);
		}
	}
	
	if((Keyboard::isKeyPressed(Keyboard::Left)
	 || Keyboard::isKeyPressed(Keyboard::Right))
	&& (Keyboard::isKeyPressed(Keyboard::Up)
	 || Keyboard::isKeyPressed(Keyboard::Down))) {
		m_character.setVelocity(m_character.vx() / 1.4f, m_character.vy() / 1.4f);
	}
	
	m_character.mapCollisions();
	
	m_character.move(m_character.vx() * 0.4f,
					 m_character.vy() * 0.4f);
	
	m_character.setVelocity(0, 0);
}

void MovingState::update() {
	if(!Keyboard::isKeyPressed(Keyboard::Left)
	&& !Keyboard::isKeyPressed(Keyboard::Right)
	&& !Keyboard::isKeyPressed(Keyboard::Up)
	&& !Keyboard::isKeyPressed(Keyboard::Down)) {
		setNextState([]{ return new StandingState; });
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::A)
	&& m_character.inventory().weaponA() != nullptr) {
		setNextState(m_character.inventory().weaponA()->playerStateTransition());
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::B)
	&& m_character.inventory().weaponB() != nullptr) {
		setNextState(m_character.inventory().weaponB()->playerStateTransition());
	}
	
	move();
}

void MovingState::render() {
	m_character.playAnimation(m_character.x(), m_character.y(), m_character.direction());
}

