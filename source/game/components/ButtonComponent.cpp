/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
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

