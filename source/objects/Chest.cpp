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
}

Chest::~Chest() {
}

void Chest::onEvent(u8 event) {
	if(event == Map::EventType::ChestOpened) {
		Sound::Effect::chest.play();
		
		MapManager::currentMap->setTile(m_x / 16, m_y / 16 - 1, 240);
		
		GameStateManager::push(new ChestOpenedState(GameStateManager::top(), m_x, m_y));
	}
}

