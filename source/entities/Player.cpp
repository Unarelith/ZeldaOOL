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
#include "Keyboard.hpp"
#include "TimeManager.hpp"
#include "TilesData.hpp"
#include "MapManager.hpp"
#include "MapHelper.hpp"
#include "EffectManager.hpp"
#include "Player.hpp"

#include "Sword.hpp"

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
	
	m_weapon = new Sword;
	
	m_sword.load("graphics/animations/sword.png", 16, 16);
	m_sword.addAnimation({0, 4, 8, 8}, 90);
	m_sword.addAnimation({1, 5, 9, 9}, 90);
	m_sword.addAnimation({2, 6, 10, 10}, 90);
	m_sword.addAnimation({3, 7, 11, 11}, 90);
}

Player::~Player() {
	delete m_weapon;
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
	
	if(onTile(TilesData::TileType::SlowingTile)) {
		m_vx /= 2;
		m_vy /= 2;
	}
	
	if(onTile(TilesData::TileType::LowGrassTile)) {
		m_vx /= 4;
		m_vx *= 3;
		
		m_vy /= 4;
		m_vy *= 3;
	}
	
	if(onTile(TilesData::TileType::Button)) {
		MapManager::currentMap->sendEvent(Map::EventType::ButtonPressed);
	}
}

void Player::move() {
	m_state = State::Standing;
	
	if(Keyboard::isKeyPressed(Keyboard::Left)) {
		m_state = State::Moving;
		m_vx = -1;
		
		if(!Keyboard::isKeyPressed(Keyboard::Up)
		&& !Keyboard::isKeyPressed(Keyboard::Down)) {
			m_direction = Direction::Left;
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Right)) {
		m_state = State::Moving;
		m_vx = 1;
		
		if(!Keyboard::isKeyPressed(Keyboard::Up)
		&& !Keyboard::isKeyPressed(Keyboard::Down)) {
			m_direction = Direction::Right;
		}
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Up)) {
		m_state = State::Moving;
		m_vy = -1;
		
		if(!Keyboard::isKeyPressed(Keyboard::Left)
		&& !Keyboard::isKeyPressed(Keyboard::Right)) {
			m_direction = Direction::Up;
		}
	}
	else if(Keyboard::isKeyPressed(Keyboard::Down)) {
		m_state = State::Moving;
		m_vy = 1;
		
		if(!Keyboard::isKeyPressed(Keyboard::Left)
		&& !Keyboard::isKeyPressed(Keyboard::Right)) {
			m_direction = Direction::Down;
		}
	}
	
	if((Keyboard::isKeyPressed(Keyboard::Left)
	 || Keyboard::isKeyPressed(Keyboard::Right))
	&& (Keyboard::isKeyPressed(Keyboard::Up)
	 || Keyboard::isKeyPressed(Keyboard::Down))) {
		m_vx /= 1.4;
		m_vy /= 1.4;
	}
	
	mapCollisions();
	
	m_x += m_vx * 60 * TimeManager::dt;
	m_y += m_vy * 60 * TimeManager::dt;
	
	m_vx = 0;
	m_vy = 0;
}

void Player::update() {
	if(m_state != State::UsingWeapon) {
		move();
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::A) && m_weapon) {
		if(m_weapon->reset()) {
			m_state = State::UsingWeapon;
		}
	}
	
	if(m_state == State::UsingWeapon) {
		if(m_weapon->update()) {
			m_state = State::Standing;
		}
	}
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
		case State::UsingWeapon:
			m_weapon->draw();
			break;
	}
	
	if(m_state != State::UsingWeapon) {
		EffectManager::drawEffects(this);
	}
}

