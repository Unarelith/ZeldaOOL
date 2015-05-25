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
		
		m_cursorPosition.x--;
	}
	
	if(GamePad::isKeyPressedWithDelay(GameKey::Right, 250)) {
		AudioPlayer::playEffect("menuCursor");
		
		m_cursorPosition.x++;
	}
	
	if(GamePad::isKeyPressedWithDelay(GameKey::Up, 250)) {
		AudioPlayer::playEffect("menuCursor");
		
		m_cursorPosition.y--;
	}
	
	if(GamePad::isKeyPressedWithDelay(GameKey::Down, 250)) {
		AudioPlayer::playEffect("menuCursor");
		
		m_cursorPosition.y++;
	}
	
	if(m_cursorPosition.x < 0) {
		m_cursorPosition.x = 3;
		m_cursorPosition.y--;
	}
	
	if(m_cursorPosition.x > 3) {
		m_cursorPosition.x = 0;
		m_cursorPosition.y++;
	}
	
	if(m_cursorPosition.y < 0) m_cursorPosition.y = 3;
	if(m_cursorPosition.y > 3) m_cursorPosition.y = 0;
	
	auto &playerInventory = Scene::player->get<InventoryComponent>();
	
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		AudioPlayer::playEffect("menuSelect");
		
		playerInventory.equipWeapon(m_cursorPosition, GameKey::A);
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::B)) {
		AudioPlayer::playEffect("menuSelect");
		
		playerInventory.equipWeapon(m_cursorPosition, GameKey::B);
	}
}

void Menu::draw() {
	m_background.draw({0, 16});
	
	m_cursor.draw({(float)(22 + m_cursorPosition.x * 32), (float)(25 + m_cursorPosition.y * 24)});
	
	auto &playerInventory = Scene::player->get<InventoryComponent>();
	
	for(u8 x = 0 ; x < 4 ; x++) {
		for(u8 y = 0 ; y < 4 ; y++) {
			auto *weapon = playerInventory.getWeapon({x, y});
			
			if(weapon) weapon->icon().draw({(float)(22 + x * 32), (float)(23 + y * 24)});
		}
	}
}

