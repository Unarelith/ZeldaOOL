/*
 * =====================================================================================
 *
 *       Filename:  Player.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:17:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "MapHelper.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "PushingState.hpp"
#include "StandingState.hpp"
#include "TilesData.hpp"
#include "WeaponManager.hpp"

Player::Player() {
}

Player::~Player() {
}

void Player::load() {
	m_defaultState = [](){
		return new StandingState();
	};
	
	Battler::load("characters-link", 4 * 16, 3 * 16, 16, 16, Direction::Down);
	
	m_battlerType = BattlerType::TypePlayer;
	
	// Movement
	addAnimation({4, 0}, 110);
	addAnimation({5, 1}, 110);
	addAnimation({6, 2}, 110);
	addAnimation({7, 3}, 110);
	
	// Pushing
	addAnimation({ 8, 12}, 90);
	addAnimation({ 9, 13}, 90);
	addAnimation({10, 14}, 90);
	addAnimation({11, 15}, 90);
	
	// Using sword
	addAnimation({16, 20, 20, 20, 20, 20, 20, 20}, 40);
	addAnimation({17, 21, 21, 21, 21, 21, 21, 21}, 40);
	addAnimation({18, 22, 22, 22, 22, 22, 22, 22}, 40);
	addAnimation({19, 23, 23, 23, 23, 23, 23, 23}, 40);
	
	// SpinAttack
	addAnimation({20, 20, 22, 22, 23, 23, 21, 21}, 50);
	
	m_maxLife = 13 * 4;
	m_life = 11 * 4;
	
	//m_hitbox = IntRect(3, 7, 10, 9);
	m_hitbox = IntRect(4, 5, 8, 10);
	
	m_inventory.setWeaponA(WeaponManager::getWeaponByID(WeaponManager::SwordID));
	
	m_inDoor = false;
}

void Player::update() {
	Battler::update();
	
	if(m_direction == Direction::Up && MapHelper::isTile(m_x + 8, m_y + 4, TilesData::TileType::ClosedChest)) {
		if(Keyboard::isKeyPressedOnce(Keyboard::A)) {
			Map::currentMap->sendEvent(Map::EventType::ChestOpened, this, Vector2i(8, -2));
		}
	}
	
	m_stateManager.update();
	
	m_stateManager.updateStates();
}

void Player::draw() {
	m_stateManager.render();
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
		
		if(test
		&& (!MapHelper::passable(m_x + collisionMatrix[i][0], m_y + collisionMatrix[i][1])
		||  !MapHelper::passable(m_x + collisionMatrix[i][2], m_y + collisionMatrix[i][3]))) {
			if(i < 2)	m_vx = 0;
			else		m_vy = 0;
			
			if((i == 0 && m_direction == Direction::Right)
			|| (i == 1 && m_direction == Direction::Left)
			|| (i == 2 && m_direction == Direction::Up)
			|| (i == 3 && m_direction == Direction::Down)) {
				m_stateManager.setNextState([](){ return new PushingState; });
			}
			
			if( MapHelper::passable(m_x + collisionMatrix[i][2], m_y + collisionMatrix[i][3])
			&& !MapHelper::passable(m_x + collisionMatrix[i][0], m_y + collisionMatrix[i][1])) {
				if(i < 2 && m_vy == 0)	m_vy = 1;
				else if(    m_vx == 0)	m_vx = 1;
				
				m_stateManager.resetNextState();
			}
			
			if( MapHelper::passable(m_x + collisionMatrix[i][0], m_y + collisionMatrix[i][1])
			&& !MapHelper::passable(m_x + collisionMatrix[i][2], m_y + collisionMatrix[i][3])) {
				if(i < 2 && m_vy == 0)	m_vy = -1;
				else if(    m_vx == 0)	m_vx = -1;
				
				m_stateManager.resetNextState();
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
		Map::currentMap->sendEvent(Map::EventType::ButtonPressed);
	}
	
	if(MapHelper::onDoor(m_x + 8, m_y + 8) && !m_inDoor) {
		m_inDoor = true;
		
		Map::currentMap->sendEvent(Map::EventType::ChangeMap, this, Vector2i(8, 8));
	}
	
	//if(!MapHelper::onDoor(m_x +  2, m_y +  2)
	//&& !MapHelper::onDoor(m_x + 14, m_y +  2)
	//&& !MapHelper::onDoor(m_x +  2, m_y + 14)
	//&& !MapHelper::onDoor(m_x + 14, m_y + 14)) {
	if(!MapHelper::onDoor(m_x + 8, m_y + 8)) {
		m_inDoor = false;
	}
}

