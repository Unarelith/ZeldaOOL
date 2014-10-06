/*
 * =====================================================================================
 *
 *       Filename:  DoorTransition.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2014 21:52:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "CharacterManager.hpp"
#include "DoorTransition.hpp"
#include "MapManager.hpp"

DoorTransition::DoorTransition(u16 area, u16 mapX, u16 mapY, u16 playerX, u16 playerY, u8 playerDirection, bool movePlayer) {
	m_nextMap = &MapManager::maps[area][mapX + mapY * MapManager::maps[area].size()];
	
	m_playerX = playerX;
	m_playerY = playerY;
	
	m_playerDirection = playerDirection;
	
	m_movePlayer = movePlayer;
	
	m_timer.start();
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	m_rect1.resize(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 16);
	m_rect2.resize(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 16);
	
	m_rect1.setPosition(0, 16);
	m_rect2.setPosition(WINDOW_WIDTH / 2, 16);
	
	CharacterManager::player.setNextStateType(PlayerState::TypeStanding);
	CharacterManager::player.updateStates();
}

DoorTransition::~DoorTransition() {
}

void DoorTransition::update() {
	if(m_rect1.x() + m_rect1.width() < 0) {
		MapManager::currentMap = m_nextMap;
		
		m_atEnd = true;
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}
	
	if(m_timer.time() > 250) {
		CharacterManager::player.setPosition(m_playerX, m_playerY);
		CharacterManager::player.setDirection(m_playerDirection);
		
		m_rect1.move(-1.5, 0);
		m_rect2.move(1.5, 0);
	}
}

void DoorTransition::draw() {
	if(m_timer.time() > 250) {
		if(m_nextMap) m_nextMap->draw();
		
		CharacterManager::player.draw();
		
		m_rect1.draw(Color::text);
		m_rect2.draw(Color::text);
		
		m_statsBar.draw();
	}
}

