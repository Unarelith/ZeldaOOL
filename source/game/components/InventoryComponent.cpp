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
#include <gk/resource/ResourceHandler.hpp>

#include "GameKey.hpp"
#include "InventoryComponent.hpp"

Weapon *InventoryComponent::addWeapon(const std::string &name) {
	for(u8 x = 0 ; x < 4 ; x++) {
		for(u8 y = 0 ; y < 4 ; y++) {
			if(!m_weapons[x][y]) {
				m_weapons[x][y] = &gk::ResourceHandler::getInstance().get<Weapon>("weapon-" + name);
				return m_weapons[x][y];
			}
		}
	}

	return nullptr;
}

void InventoryComponent::equipWeapon(u8 x, u8 y, gk::GameKey key) {
	Weapon *temp = m_weapons[x][y];

	if(key == GameKey::A) {
		m_weapons[x][y] = m_weaponA;
		m_weaponA = temp;
	}
	else if(key == GameKey::B) {
		m_weapons[x][y] = m_weaponB;
		m_weaponB = temp;
	}
}

