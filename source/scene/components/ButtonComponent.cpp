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
#include "TileMap.hpp"

void ButtonComponent::addTileChange(u16 tileX, u16 tileY, u16 newID) {
	m_tileChanges.emplace_back(tileX, tileY, -1, newID);
}

void ButtonComponent::pressedAction(u16 buttonTileX, u16 buttonTileY) {
	if(m_pressed) return;

	AudioPlayer::playEffect("chest");

	TileMap::currentMap->setTile(buttonTileX, buttonTileY, 8);

	for(auto &tileChange : m_tileChanges) {
		if(tileChange.oldID == -1) {
			tileChange.oldID = TileMap::currentMap->getTile(tileChange.tileX, tileChange.tileY);
		}

		TileMap::currentMap->setTile(tileChange.tileX,
		                             tileChange.tileY,
		                             tileChange.newID);
	}

	m_pressed = true;
}

void ButtonComponent::releasedAction(u16 buttonTileX, u16 buttonTileY) {
	if(!m_pressed) return;

	TileMap::currentMap->setTile(buttonTileX, buttonTileY, 7);

	for(auto &tileChange : m_tileChanges) {
		if(tileChange.oldID != -1) {
			TileMap::currentMap->setTile(tileChange.tileX,
			                             tileChange.tileY,
			                             tileChange.oldID);
		}
	}

	m_pressed = false;
}

