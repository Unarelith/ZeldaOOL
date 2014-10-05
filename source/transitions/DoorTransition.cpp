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
}

DoorTransition::~DoorTransition() {
}

void DoorTransition::update() {
	MapManager::currentMap = m_nextMap;
	
	CharacterManager::player.setPosition(m_playerX, m_playerY);
	CharacterManager::player.setDirection(m_playerDirection);
	
	m_atEnd = true;
}

void DoorTransition::draw() {
	
}

