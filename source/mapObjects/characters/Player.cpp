/*
 * =====================================================================================
 *
 *       Filename:  Player.cpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:17:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "GamePad.hpp"
#include "GamePadMovement.hpp"
#include "Map.hpp"
#include "NPC.hpp"
#include "Player.hpp"
#include "PushingState.hpp"
#include "StandingState.hpp"
#include "Sword.hpp"
#include "TilesInfos.hpp"

Player Player::player;

void Player::load() {
	Battler::load("characters-link", 4 * 16, 3 * 16, 16, 16, Direction::Down);
	
	std::vector<std::vector<std::pair<s16, s16>>> usingSwordPosition = {
		{{ 0,  0}, { 0,  0}, { 0,  3}, { 0,  3}, { 0,  3}, { 0,  3}, { 0,  0}, { 0,  0}},
		{{ 0,  0}, { 0,  0}, { 4,  0}, { 4,  0}, { 4,  0}, { 4,  0}, { 0,  0}, { 0,  0}},
		{{ 0,  0}, { 0,  0}, {-4,  0}, {-4,  0}, {-4,  0}, {-4,  0}, { 0,  0}, { 0,  0}},
		{{ 0,  0}, { 0,  0}, { 0, -3}, { 0, -3}, { 0, -3}, { 0, -3}, { 0,  0}, { 0,  0}}
	};
	
	std::vector<std::pair<s16, s16>> swordSpinAttackPosition = {
		{ 0,  3}, { 0,  3},
		{-4,  0}, {-4,  0},
		{ 0, -3}, { 0, -3},
		{ 4,  0}, { 4,  0}
	};
	
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
	addAnimation({16, 16, 20, 20, 20, 20, 20, 20}, usingSwordPosition[0], 40);
	addAnimation({17, 17, 21, 21, 21, 21, 21, 21}, usingSwordPosition[1], 40);
	addAnimation({18, 18, 22, 22, 22, 22, 22, 22}, usingSwordPosition[2], 40);
	addAnimation({19, 19, 23, 23, 23, 23, 23, 23}, usingSwordPosition[3], 40);
	
	// SpinAttack
	addAnimation({20, 20, 22, 22, 23, 23, 21, 21}, swordSpinAttackPosition, 50);
	
	setMovement<OldGamePadMovement>();
	addCollisionHandler(std::bind(&Player::mapCollisions, this));
	
	setNextState<StandingState>();
	m_stateManager.updateStates();
	
	m_maxLife = 13 * 4;
	m_life = 11 * 4;
	
	m_hitbox = IntRect(4, 5, 8, 10);
	
	auto &sword = m_inventory.addWeapon<Sword>();
	m_inventory.setWeaponA(sword);
}

void Player::update(bool states) {
	// Check if the player is hurt
	Battler::update();
	
	if(states) {
		// Update current state
		m_stateManager.update();
		
		// Set current state to next state if it exists
		m_stateManager.updateStates();
	}
}

void Player::draw() {
	m_stateManager.render();
	
	MapObject::draw();
}

void Player::collisionAction(MapObject &object) {
	if(object.checkType<NPC>()) {
		// FIXME: See above
		s16 vx = m_x - object.x();
		s16 vy = m_y - object.y();
		
		if(vx != 0) vx /= abs(vx);
		if(vy != 0) vy /= abs(vy);
		
		// TODO: Write an helper function for that, it could be used somewhere
		// else, in Character::updateDirection or something like that
		u8 direction = 0;
		if(vx < 0) direction = Movable::Direction::Left;
		if(vx > 0) direction = Movable::Direction::Right;
		if(vy < 0) direction = Movable::Direction::Down;
		if(vy > 0) direction = Movable::Direction::Up;
		
		if(m_direction == direction) {
			Character::mapCollisionAction(vx, vy);
		} else {
			if(vx != 0) m_vx = 0;
			if(vy != 0) m_vy = 0;
		}
	}
	else {
		if(onTile(TilesInfos::TileType::Button)) {
			object.onEvent(Map::EventType::ButtonPressed);
		}
		else if(!m_inDoor && Map::currentMap->onDoor(m_x + 8, m_y + 8)) {
			m_inDoor = true;
			
			object.onEvent(Map::EventType::ChangeMap);
		}
	}
}

// FIXME: Make an object for that, maybe using the Component pattern?
void Player::mapCollisions() {
	// Pixel-perfect link hitbox for each 4 directions
	u8 collisionMatrix[4][4] = {
		{12, 8,12,13},
		{ 4, 8, 4,13},
		{ 5, 5,10, 5},
		{ 5,15,10,15}
	};
	
	// Iterate through the directions
	for(u8 i = 0 ; i < 4 ; i++) {
		bool test;
		
		// Test the velocity vector for each direction
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
		&& (!Map::currentMap->passable(m_x + collisionMatrix[i][0], m_y + collisionMatrix[i][1])
		||  !Map::currentMap->passable(m_x + collisionMatrix[i][2], m_y + collisionMatrix[i][3]))) {
			if(i < 2)	m_vx = 0;
			else		m_vy = 0;
			
			// If the player is looking at the wall, block it
			if((i == 0 && m_direction == Direction::Right)
			|| (i == 1 && m_direction == Direction::Left)
			|| (i == 2 && m_direction == Direction::Up)
			|| (i == 3 && m_direction == Direction::Down)) {
				m_blocked = true;
			}
			
			//-----------------------------------------------------------------
			// Test collisions with tile borders in order to shift the player
			//-----------------------------------------------------------------
			if( Map::currentMap->passable(m_x + collisionMatrix[i][2], m_y + collisionMatrix[i][3])
			&& !Map::currentMap->passable(m_x + collisionMatrix[i][0], m_y + collisionMatrix[i][1])) {
				if(i < 2 && m_vy == 0)	m_vy = 1;
				else if(    m_vx == 0)	m_vx = 1;
				
				m_blocked = false;
			}
			
			if( Map::currentMap->passable(m_x + collisionMatrix[i][0], m_y + collisionMatrix[i][1])
			&& !Map::currentMap->passable(m_x + collisionMatrix[i][2], m_y + collisionMatrix[i][3])) {
				if(i < 2 && m_vy == 0)	m_vy = -1;
				else if(    m_vx == 0)	m_vx = -1;
				
				m_blocked = false;
			}
		}
	}
	
	// Check collisions with every object in Map::currentMap
	Map::currentMap->scene().checkCollisionsFor(this);
	
	if(m_blocked) setNextState<PushingState>();
	
	if(onTile(TilesInfos::TileType::SlowingTile)) {
		m_vx /= 2;
		m_vy /= 2;
	}
	
	if(onTile(TilesInfos::TileType::LowGrassTile)) {
		m_vx /= 4;
		m_vx *= 3;
		
		m_vy /= 4;
		m_vy *= 3;
	}
	
	// Check if the player is not on a door anymore
	if(m_inDoor && !Map::currentMap->onDoor(m_x + 8, m_y + 8)) {
		m_inDoor = false;
	}
}

