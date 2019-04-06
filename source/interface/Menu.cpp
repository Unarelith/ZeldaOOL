/*
 * =====================================================================================
 *
 *       Filename:  Menu.cpp
 *
 *    Description:
 *
 *        Created:  02/10/2014 14:33:28
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/input/GamePad.hpp>
#include <gk/resource/AudioPlayer.hpp>

#include "GameKey.hpp"
#include "InventoryComponent.hpp"
#include "Menu.hpp"
#include "World.hpp"

Menu::Menu() {
	m_background.setPosition(0, 16);
}

void Menu::update() {
	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Left, 250)) {
		gk::AudioPlayer::playSound("sfx-menuCursor");

		m_cursorX--;
	}

	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Right, 250)) {
		gk::AudioPlayer::playSound("sfx-menuCursor");

		m_cursorX++;
	}

	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Up, 250)) {
		gk::AudioPlayer::playSound("sfx-menuCursor");

		m_cursorY--;
	}

	if(gk::GamePad::isKeyPressedWithDelay(GameKey::Down, 250)) {
		gk::AudioPlayer::playSound("sfx-menuCursor");

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
		gk::AudioPlayer::playSound("sfx-menuSelect");

		playerInventory.equipWeapon(m_cursorX, m_cursorY, GameKey::A);
	}

	if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
		gk::AudioPlayer::playSound("sfx-menuSelect");

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

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
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

