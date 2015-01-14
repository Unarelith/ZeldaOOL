/*
 * =====================================================================================
 *
 *       Filename:  ChestObject.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/10/2014 20:24:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "ChestObject.hpp"
#include "ChestOpenedState.hpp"
#include "GameStateManager.hpp"
#include "Map.hpp"
#include "RupeeCollectable.hpp"

ChestObject::ChestObject(float x, float y) : Object(x, y) {
	m_opened = false;
	
	m_collectable = new RupeeCollectable(x, y, 30);
}

ChestObject::~ChestObject() {
}

void ChestObject::onEvent(u8 event) {
	if(event == Map::EventType::ChestOpened) {
		AudioPlayer::playEffect("chest");
		
		m_opened = true;
		
		resetTiles(Map::currentMap);
		
		GameStateManager::push(new ChestOpenedState(GameStateManager::top(), m_x, m_y, m_collectable));
	}
}

void ChestObject::resetTiles(Map *map) {
	if(m_opened) {
		map->setTile(m_x / 16, m_y / 16, 240);
	}
}

