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
#include "CharacterManager.hpp"
#include "Chest.hpp"
#include "DialogState.hpp"
#include "GameStateManager.hpp"
#include "Map.hpp"
#include "Sound.hpp"

Chest::Chest(float x, float y) : Object(x, y) {
	m_state = Opening;
}

Chest::~Chest() {
}

void Chest::onEvent(u8 event) {
	if(event == Map::EventType::ChestOpened) {
		Sound::Effect::chest.play();
		
		MapManager::currentMap->setTile(m_x / 16, m_y / 16 - 1, 240);
		
		Sound::Effect::itemNew.play();
		
		CharacterManager::player.addRupees(30);
		
		GameStateManager::push(new DialogState(GameStateManager::top(), "Vous obtenez [2]30 [2]Rubis[0]!\nC'est bien."));
	}
}

