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
#include "MapHelper.hpp"
#include "Player.hpp"

Player::Player() : Character("graphics/characters/link.png", 64, 64, 16, 16, Direction::Down) {
	m_state = State::Standing;
	
	addAnimation({4, 0}, 110);
	addAnimation({5, 1}, 110);
	addAnimation({6, 2}, 110);
	addAnimation({7, 3}, 110);
	
	addAnimation({ 8, 12}, 90);
	addAnimation({ 9, 13}, 90);
	addAnimation({10, 14}, 90);
	addAnimation({11, 15}, 90);
	
	addAnimation({16, 20, 20, 20}, 90);
	addAnimation({17, 21, 21, 21}, 90);
	addAnimation({18, 22, 22, 22}, 90);
	addAnimation({19, 23, 23, 23}, 90);
	
	m_maxLife = 13 * 4;
	m_life = 11 * 4;
	
	m_rupees = 197;
}

Player::~Player() {
}

void Player::mapCollisions() {
	u8 collisionMatrix[4][4] = {
		{12, 8,12,13},
		{ 3, 8, 3,13},
		{ 5, 5,10, 5},
		{ 5,15,10,15}
	};
	
	for(u8 i = 0 ; i < 4 ; i++) {
		bool test;
		
		if(i == 0) {
			test = (m_vx > 0);
		}
		else if(i == 1) {
			test = (m_vx < 0);
		}
		else if(i == 2) {
			test = (m_vy < 0);
		}
		else if(i == 3) {
			test = (m_vy > 0);
		}
		
		if(test
		&& (!MapHelper::passable(m_x + collisionMatrix[i][0], m_y + collisionMatrix[i][1])
		||  !MapHelper::passable(m_x + collisionMatrix[i][2], m_y + collisionMatrix[i][3]))) {
			if(i < 2)	m_vx = 0;
			else		m_vy = 0;
			
			if((i == 0 && m_direction == Direction::Right)
			|| (i == 1 && m_direction == Direction::Left)
			|| (i == 2 && m_direction == Direction::Up)
			|| (i == 3 && m_direction == Direction::Down)) {
				m_state = State::Colliding;
			}
			
			if( MapHelper::passable(m_x + collisionMatrix[i][2], m_y + collisionMatrix[i][3])
			&& !MapHelper::passable(m_x + collisionMatrix[i][0], m_y + collisionMatrix[i][1])) {
				if(i < 2 && m_vy == 0)	m_vy = 1;
				else if(    m_vx == 0)	m_vx = 1;
				
				m_state = State::Moving;
			}
			
			if( MapHelper::passable(m_x + collisionMatrix[i][0], m_y + collisionMatrix[i][1])
			&& !MapHelper::passable(m_x + collisionMatrix[i][2], m_y + collisionMatrix[i][3])) {
				if(i < 2 && m_vy == 0)	m_vy = -1;
				else if(    m_vx == 0)	m_vx = -1;
				
				m_state = State::Moving;
			}
		}
	}
	
	/*if(((stairsTile(m_x + 6, m_y + 11))
	&&  (stairsTile(m_x + 7, m_y + 11))
	&&  (stairsTile(m_x + 6, m_y + 12))
	&&  (stairsTile(m_x + 7, m_y + 12)))
	&& m_vy != 0) {
		m_vx /= 2;
		m_vy /= 2;
	}
	
	if((lowGrassTile(m_x + 6, m_y + 11))
	&& (lowGrassTile(m_x + 7, m_y + 11))
	&& (lowGrassTile(m_x + 6, m_y + 12))
	&& (lowGrassTile(m_x + 7, m_y + 12))) {
		m_vx /= 4;
		m_vx *= 3;
		
		m_vy /= 4;
		m_vy *= 3;
		
		SpriteManager::grassEffect->drawFrame(m_x, m_y, 0);
	} else {
		SpriteManager::grassEffect->clear();
	}
	
	if((lowWaterTile(m_x + 6, m_y + 11))
	&& (lowWaterTile(m_x + 7, m_y + 11))
	&& (lowWaterTile(m_x + 6, m_y + 12))
	&& (lowWaterTile(m_x + 7, m_y + 12))) {
		SpriteManager::lowWaterEffect->playAnimation(m_x, m_y + 8, 0);
	} else {
		SpriteManager::lowWaterEffect->clear();
	}*/
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
	
	mapCollisions();
	
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

