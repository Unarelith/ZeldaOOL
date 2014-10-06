/*
 * =====================================================================================
 *
 *       Filename:  Door.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2014 18:13:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Door.hpp"
#include "DoorTransition.hpp"
#include "GameStateManager.hpp"
#include "Map.hpp"
#include "Sound.hpp"
#include "TransitionState.hpp"

Door::Door(float x, float y) : Object(x, y) {
}

Door::~Door() {
}

void Door::setDestination(u16 area, u8 mapX, u8 mapY, float playerX, float playerY, u8 playerDirection) {
	m_area = area;
	
	m_mapX = mapX;
	m_mapY = mapY;
	
	m_playerX = playerX;
	m_playerY = playerY;
	
	m_playerDirection = playerDirection;
}

void Door::onEvent(u8 event) {
	if(event == Map::EventType::ChangeMap) {
		Sound::Effect::mapStairs.play();
		
		GameStateManager::push(new TransitionState(new DoorTransition(m_area, m_mapX, m_mapY, m_playerX, m_playerY, m_playerDirection)));
	}
}

