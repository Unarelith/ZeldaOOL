/*
 * =====================================================================================
 *
 *       Filename:  Player.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 21:53:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GameState.hpp"
#include "KeyboardMovement.hpp"
#include "Player.hpp"

Player::Player() {
	Character::load("link");
	
	// Movement
	addAnimation({4, 0}, 110);
	addAnimation({5, 1}, 110);
	addAnimation({6, 2}, 110);
	addAnimation({7, 3}, 110);
	
	setPosition(96, 64);
	
	setMovement(new KeyboardMovement);
	
	addCollisionHandler(std::bind(&Player::mapCollisions, this));
	
	m_maxLife = 13 * 4;
	m_life = 11 * 4;
}

Player::~Player() {
}

void Player::collisionAction(Character &character) {
	m_vx = 0;
	m_vy = 0;
}

void Player::mapCollisions() {
	u8 collisionMatrix[4][4] = {
		{12, 8,12,13},
		{ 4, 8, 4,13},
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
		
		Map &currentMap = GameState::getInstance().currentMap();
		
		if(test
		&& (!currentMap.passable(getPosition().x + collisionMatrix[i][0], getPosition().y + collisionMatrix[i][1])
		||  !currentMap.passable(getPosition().x + collisionMatrix[i][2], getPosition().y + collisionMatrix[i][3]))) {
			if(i < 2)	m_vx = 0;
			else		m_vy = 0;
			
			if((i == 0 && m_direction == Direction::Right)
			|| (i == 1 && m_direction == Direction::Left)
			|| (i == 2 && m_direction == Direction::Up)
			|| (i == 3 && m_direction == Direction::Down)) {
				m_blocked = true;
			}
			
			if( currentMap.passable(getPosition().x + collisionMatrix[i][2], getPosition().y + collisionMatrix[i][3])
			&& !currentMap.passable(getPosition().x + collisionMatrix[i][0], getPosition().y + collisionMatrix[i][1])) {
				if(i < 2 && m_vy == 0)	m_vy = 1;
				else if(    m_vx == 0)	m_vx = 1;
				
				m_blocked = false;
			}
			
			if( currentMap.passable(getPosition().x + collisionMatrix[i][0], getPosition().y + collisionMatrix[i][1])
			&& !currentMap.passable(getPosition().x + collisionMatrix[i][2], getPosition().y + collisionMatrix[i][3])) {
				if(i < 2 && m_vy == 0)	m_vy = -1;
				else if(    m_vx == 0)	m_vx = -1;
				
				m_blocked = false;
			}
		}
	}
}

