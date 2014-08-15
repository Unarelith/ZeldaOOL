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
	m_state = State::Standing;
	
	addAnimation({4, 0}, 135);
	addAnimation({5, 1}, 135);
	addAnimation({6, 2}, 135);
	addAnimation({7, 3}, 135);
	
	addAnimation({ 8, 12}, 135);
	addAnimation({ 9, 13}, 135);
	addAnimation({10, 14}, 135);
	addAnimation({11, 15}, 135);
	
	addAnimation({16, 20, 20, 20}, 90);
	addAnimation({17, 21, 21, 21}, 90);
	addAnimation({18, 22, 22, 22}, 90);
	addAnimation({19, 23, 23, 23}, 90);
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
		m_vx /= 1.5;
		m_vy /= 1.5;
	}
	
	m_x += m_vx;
	m_y += m_vy;
	
	m_vx = 0;
	m_vy = 0;
}

void Player::draw() {
	switch(m_state) {
		case State::Standing:
			drawFrame(m_x, m_y, m_direction);
			break;
		case State::Moving:
			playAnimation(m_x, m_y, m_direction);
			break;
		case State::Colliding:
			playAnimation(m_x, m_y, m_direction + 4);
			break;
		case State::Attacking:
			playAnimation(m_x, m_y, m_direction + 8);
			break;
	}
}

