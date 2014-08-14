/*
 * =====================================================================================
 *
 *       Filename:  Player.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/08/2014 19:11:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Player.hpp"

Player::Player() : Character("graphics/characters/link.png", 64, 64, 16, 16, Direction::Down) {
	addAnimation({4, 0}, 135);
	addAnimation({5, 1}, 135);
	addAnimation({6, 2}, 135);
	addAnimation({7, 3}, 135);
}

Player::~Player() {
}

void Player::move() {
	m_state = State::Standing;
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_state = State::Moving;
		m_vx = -1;
		
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			m_direction = Direction::Left;
		}
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_state = State::Moving;
		m_vx = 1;
		
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			m_direction = Direction::Right;
		}
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_state = State::Moving;
		m_vy = -1;
		
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			m_direction = Direction::Up;
		}
	}
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_state = State::Moving;
		m_vy = 1;
		
		if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			m_direction = Direction::Down;
		}
	}
	
	m_vx *= 2;
	m_vy *= 2;
	
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
	 || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	&& (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
	 || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
		m_vx /= 2;
		m_vy /= 2;
	}
	
	m_x += m_vx;
	m_y += m_vy;
	
	m_vx = 0;
	m_vy = 0;
}

