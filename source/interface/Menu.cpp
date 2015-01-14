/*
 * =====================================================================================
 *
 *       Filename:  Menu.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/10/2014 14:33:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "CharacterManager.hpp"
#include "Keyboard.hpp"
#include "Menu.hpp"
#include "Weapon.hpp"

Menu::Menu() {
	m_background.load("interface-menuBackground");
	m_cursor.load("interface-menuCursor");
	
	m_cursorX = 0;
	m_cursorY = 0;
}

Menu::~Menu() {
}

void Menu::update() {
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Left, 250)) {
		AudioPlayer::playEffect("menuCursor");
		
		m_cursorX--;
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Right, 250)) {
		AudioPlayer::playEffect("menuCursor");
		
		m_cursorX++;
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Up, 250)) {
		AudioPlayer::playEffect("menuCursor");
		
		m_cursorY--;
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Down, 250)) {
		AudioPlayer::playEffect("menuCursor");
		
		m_cursorY++;
	}
	
	if(m_cursorX < 0) {
		m_cursorX = 3;
		m_cursorY--;
	}
	
	if(m_cursorY < 0) {
		m_cursorY = 3;
	}
	
	if(m_cursorX > 3) {
		m_cursorX = 0;
		m_cursorY++;
	}
	
	if(m_cursorY > 3) {
		m_cursorY = 0;
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::A)) {
		AudioPlayer::playEffect("menuSelect");
		
		Weapon *weaponA = CharacterManager::player.inventory().weaponA();
		Weapon *newWeaponA = CharacterManager::player.inventory().getWeaponByPosition(Vector2i(m_cursorX, m_cursorY));
		
		if(weaponA != nullptr) {
			CharacterManager::player.inventory().setWeaponA(nullptr);
			CharacterManager::player.inventory().addWeapon(weaponA->id(), Vector2i(m_cursorX, m_cursorY));
		}
		
		if(newWeaponA != nullptr) {
			CharacterManager::player.inventory().removeWeaponByID(newWeaponA->id());
			CharacterManager::player.inventory().setWeaponA(newWeaponA);
		}
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::B)) {
		AudioPlayer::playEffect("menuSelect");
		
		Weapon *weaponB = CharacterManager::player.inventory().weaponB();
		Weapon *newWeaponB = CharacterManager::player.inventory().getWeaponByPosition(Vector2i(m_cursorX, m_cursorY));
		
		if(weaponB != nullptr) {
			CharacterManager::player.inventory().setWeaponB(nullptr);
			CharacterManager::player.inventory().addWeapon(weaponB->id(), Vector2i(m_cursorX, m_cursorY));
		}
		
		if(newWeaponB != nullptr) {
			CharacterManager::player.inventory().removeWeaponByID(newWeaponB->id());
			CharacterManager::player.inventory().setWeaponB(newWeaponB);
		}
	}
}

void Menu::draw() {
	m_background.draw(0, 16);
	
	m_cursor.draw(22 + m_cursorX * 32, 25 + m_cursorY * 24);
	
	for(u8 y = 0 ; y < 4 ; y++) {
		for(u8 x = 0 ; x < 4 ; x++) {
			Weapon *currentWeapon = CharacterManager::player.inventory().getWeaponByPosition(Vector2i(x, y));
			
			if(currentWeapon != nullptr) {
				currentWeapon->icon().draw(22 + x * 32, 23 + y * 24);
			}
		}
	}
}

