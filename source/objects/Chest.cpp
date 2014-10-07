/*
 * =====================================================================================
 *
 *       Filename:  Chest.cpp
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
#include "Chest.hpp"
#include "ChestOpenedState.hpp"
#include "GameStateManager.hpp"
#include "MapManager.hpp"
#include "Sound.hpp"

Chest::Chest(float x, float y) : Object(x, y) {
	m_opened = false;
}

Chest::~Chest() {
}

void Chest::onEvent(u8 event) {
	if(event == Map::EventType::ChestOpened) {
		Sound::Effect::chest.play();
		
		m_opened = true;
		
		resetTiles(MapManager::currentMap);
		
		GameStateManager::push(new ChestOpenedState(GameStateManager::top(), m_x, m_y));
	}
}

void Chest::resetTiles(Map *map) {
	if(m_opened) {
		map->setTile(m_x / 16, m_y / 16 - 1, 240);
	}
}

