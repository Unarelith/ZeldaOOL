/*
 * =====================================================================================
 *
 *       Filename:  ButtonComponent.cpp
 *
 *    Description:
 *
 *        Created:  19/02/2015 16:27:28
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
// #include <gk/audio/AudioPlayer.hpp> // FIXME: GameKit

#include "ButtonComponent.hpp"
#include "World.hpp"

void ButtonComponent::addTileChange(u16 tileX, u16 tileY, u16 newID) {
	m_tileChanges.emplace_back(tileX, tileY, -1, newID);
}

void ButtonComponent::pressedAction(u16 buttonTileX, u16 buttonTileY) {
	if(m_pressed) return;

	// gk::AudioPlayer::playSound("sfx-chest"); // FIXME: GameKit

	World::getInstance().currentMap()->setTile(buttonTileX, buttonTileY, 8);

	for(auto &tileChange : m_tileChanges) {
		if(tileChange.oldID == -1) {
			tileChange.oldID = World::getInstance().currentMap()->getTile(tileChange.tileX, tileChange.tileY);
		}

		World::getInstance().currentMap()->setTile(tileChange.tileX,
								 tileChange.tileY,
								 tileChange.newID);
	}

	m_pressed = true;
}

void ButtonComponent::releasedAction(u16 buttonTileX, u16 buttonTileY) {
	if(!m_pressed) return;

	World::getInstance().currentMap()->setTile(buttonTileX, buttonTileY, 7);

	for(auto &tileChange : m_tileChanges) {
		if(tileChange.oldID != -1) {
			World::getInstance().currentMap()->setTile(tileChange.tileX,
									 tileChange.tileY,
									 tileChange.oldID);
		}
	}

	m_pressed = false;
}

