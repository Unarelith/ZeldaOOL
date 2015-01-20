/*
 * =====================================================================================
 *
 *       Filename:  ButtonObject.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/01/2015 02:05:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ButtonObject.hpp"
#include "Map.hpp"
#include "SoundEffect.hpp"

void ButtonObject::addTileChange(u16 tileX, u16 tileY, u16 newTileID) {
	m_mapChanges.emplace_back(tileX, tileY, newTileID);
}

void ButtonObject::onEvent(u8 event) {
	if(event == Map::EventType::ButtonPressed) {
		SoundEffect::play("chest");
		
		Map::currentMap->setTile(m_x / 16, m_y / 16, 8);
		
		for(auto &it : m_mapChanges) {
			Map::currentMap->setTile(std::get<0>(it), std::get<1>(it), std::get<2>(it));
		}
	}
}

