/*
 * =====================================================================================
 *
 *       Filename:  Menu.cpp
 *
 *    Description:
 *
 *        Created:  02/10/2014 14:33:28
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "GamePad.hpp"
#include "InventoryComponent.hpp"
#include "Menu.hpp"
#include "Scene.hpp"

void Menu::update() {
	if(GamePad::isKeyPressedWithDelay(GameKey::Left, 250)) {
		AudioPlayer::playEffect("menuCursor");

		m_cursorX--;
	}

	if(GamePad::isKeyPressedWithDelay(GameKey::Right, 250)) {
		AudioPlayer::playEffect("menuCursor");

		m_cursorX++;
	}

	if(GamePad::isKeyPressedWithDelay(GameKey::Up, 250)) {
		AudioPlayer::playEffect("menuCursor");

		m_cursorY--;
	}

	if(GamePad::isKeyPressedWithDelay(GameKey::Down, 250)) {
		AudioPlayer::playEffect("menuCursor");

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

	auto &playerInventory = Scene::player->get<InventoryComponent>();

	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		AudioPlayer::playEffect("menuSelect");

		playerInventory.equipWeapon(m_cursorX, m_cursorY, GameKey::A);
	}

	if(GamePad::isKeyPressedOnce(GameKey::B)) {
		AudioPlayer::playEffect("menuSelect");

		playerInventory.equipWeapon(m_cursorX, m_cursorY, GameKey::B);
	}
}

void Menu::draw() {
	m_background.draw(0, 16);

	m_cursor.draw(22 + m_cursorX * 32, 25 + m_cursorY * 24);

	auto &playerInventory = Scene::player->get<InventoryComponent>();

	for(u8 x = 0 ; x < 4 ; x++) {
		for(u8 y = 0 ; y < 4 ; y++) {
			auto *weapon = playerInventory.getWeapon(x, y);

			if(weapon) weapon->icon().draw(22 + x * 32, 23 + y * 24);
		}
	}
}

