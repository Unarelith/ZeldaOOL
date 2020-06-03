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
// #include <gk/audio/AudioPlayer.hpp> // FIXME: GAMEKIT
#include <gk/core/input/GamePad.hpp>

#include "GameKey.hpp"
#include "InventoryComponent.hpp"
#include "Menu.hpp"
#include "World.hpp"

Menu::Menu() {
	m_background.setPosition(0, 16);
}

void Menu::update() {
	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Left, 250)) {
		// gk::AudioPlayer::playSound("sfx-menuCursor"); // FIXME: GAMEKIT

		m_cursorX--;
	}

	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Right, 250)) {
		// gk::AudioPlayer::playSound("sfx-menuCursor"); // FIXME: GAMEKIT

		m_cursorX++;
	}

	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Up, 250)) {
		// gk::AudioPlayer::playSound("sfx-menuCursor"); // FIXME: GAMEKIT

		m_cursorY--;
	}

	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Down, 250)) {
		// gk::AudioPlayer::playSound("sfx-menuCursor"); // FIXME: GAMEKIT

		m_cursorY++;
	}

	if(m_cursorX < 0) {
		m_cursorX = 3;
		m_cursorY--;
	}

	if(m_cursorX > 3) {
		m_cursorX = 0;
		m_cursorY++;
	}

	if(m_cursorY < 0) m_cursorY = 3;
	if(m_cursorY > 3) m_cursorY = 0;

	auto &playerInventory = World::getInstance().player().get<InventoryComponent>();

	if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
		// gk::AudioPlayer::playSound("sfx-menuSelect"); // FIXME: GAMEKIT

		playerInventory.equipWeapon(m_cursorX, m_cursorY, GameKey::A);
	}

	if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
		// gk::AudioPlayer::playSound("sfx-menuSelect"); // FIXME: GAMEKIT

		playerInventory.equipWeapon(m_cursorX, m_cursorY, GameKey::B);
	}

	m_cursor.setPosition(22 + m_cursorX * 32, 25 + m_cursorY * 24);

	for(u8 x = 0 ; x < 4 ; x++) {
		for(u8 y = 0 ; y < 4 ; y++) {
			auto *weapon = playerInventory.getWeapon(x, y);

			if(weapon) weapon->icon().setPosition(22 + x * 32, 23 + y * 24);
		}
	}
}

void Menu::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.draw(m_background, states);

	target.draw(m_cursor, states);

	auto &playerInventory = World::getInstance().player().get<InventoryComponent>();

	for(u8 x = 0 ; x < 4 ; x++) {
		for(u8 y = 0 ; y < 4 ; y++) {
			auto *weapon = playerInventory.getWeapon(x, y);

			if(weapon) target.draw(weapon->icon(), states);
		}
	}
}

