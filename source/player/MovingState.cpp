/*
 * =====================================================================================
 *
 *       Filename:  MovingState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 04:55:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "EffectManager.hpp"
#include "StandingState.hpp"
#include "MovingState.hpp"

MovingState::MovingState() {
	m_stateType = StateType::TypeMoving;
	m_nextStateType = StateType::TypeMoving;
}

MovingState::~MovingState() {
}

void MovingState::move() {
	if(Keyboard::isKeyPressed(Keyboard::Left)) {
		m_player.setVX(-1);
		
		if(!Keyboard::isKeyPressed(Keyboard::Up)
		&& !Keyboard::isKeyPressed(Keyboard::Down)) {
			m_player.setDirection(Player::Direction::Left);
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Right)) {
		m_player.setVX(1);
		
		if(!Keyboard::isKeyPressed(Keyboard::Up)
		&& !Keyboard::isKeyPressed(Keyboard::Down)) {
			m_player.setDirection(Player::Direction::Right);
		}
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Up)) {
		m_player.setVY(-1);
		
		if(!Keyboard::isKeyPressed(Keyboard::Left)
		&& !Keyboard::isKeyPressed(Keyboard::Right)) {
			m_player.setDirection(Player::Direction::Up);
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Down)) {
		m_player.setVY(1);
		
		if(!Keyboard::isKeyPressed(Keyboard::Left)
		&& !Keyboard::isKeyPressed(Keyboard::Right)) {
			m_player.setDirection(Player::Direction::Down);
		}
	}
	
	if((Keyboard::isKeyPressed(Keyboard::Left)
	 || Keyboard::isKeyPressed(Keyboard::Right))
	&& (Keyboard::isKeyPressed(Keyboard::Up)
	 || Keyboard::isKeyPressed(Keyboard::Down))) {
		m_player.setVelocity(m_player.vx() / 1.4, m_player.vy() / 1.4);
	}
	
	m_player.mapCollisions();
	
	m_player.move(m_player.vx() * 60 * TimeManager::dt,
				  m_player.vy() * 60 * TimeManager::dt);
	
	m_player.setVelocity(0, 0);
}

void MovingState::update() {
	if(Keyboard::isKeyPressed(Keyboard::A)) {
		m_nextStateType = StateType::TypeSword;
	}
	
	if(!Keyboard::isKeyPressed(Keyboard::Left)
	&& !Keyboard::isKeyPressed(Keyboard::Right)
	&& !Keyboard::isKeyPressed(Keyboard::Up)
	&& !Keyboard::isKeyPressed(Keyboard::Down)) {
		m_nextStateType = StateType::TypeStanding;
	}
	
	move();
}

void MovingState::draw() {
	m_player.playAnimation(m_player.x(), m_player.y(), m_player.direction());
	
	EffectManager::drawEffects(&m_player);
}

