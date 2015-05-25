/*
 * =====================================================================================
 *
 *       Filename:  ButtonComponent.cpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 16:27:28
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "ButtonComponent.hpp"
#include "Map.hpp"

void ButtonComponent::addTileChange(Vector2u16 tile, u16 newID) {
	m_tileChanges.emplace_back(tile, -1, newID);
}

void ButtonComponent::pressedAction(Vector2u16 buttonTile) {
	if(m_pressed) return;
	
	AudioPlayer::playEffect("chest");
	
	Map::currentMap->setTile(buttonTile, 8);
	
	for(auto &tileChange : m_tileChanges) {
		if(tileChange.oldID == -1) {
			tileChange.oldID = Map::currentMap->getTile(tileChange.tile);
		}
		
		Map::currentMap->setTile(tileChange.tile, tileChange.newID);
	}
	
	m_pressed = true;
}

void ButtonComponent::releasedAction(Vector2u16 buttonTile) {
	if(!m_pressed) return;
	
	Map::currentMap->setTile(buttonTile, 7);
	
	for(auto &tileChange : m_tileChanges) {
		if(tileChange.oldID != -1) {
			Map::currentMap->setTile(tileChange.tile, tileChange.oldID);
		}
	}
	
	m_pressed = false;
}

