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
#include "Player.hpp"
#include "Keyboard.hpp"
#include "Menu.hpp"
#include "SoundEffect.hpp"
#include "Weapon.hpp"

void Menu::update() {
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Left, 250)) {
		SoundEffect::play("menuCursor");
		
		m_cursorX--;
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Right, 250)) {
		SoundEffect::play("menuCursor");
		
		m_cursorX++;
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Up, 250)) {
		SoundEffect::play("menuCursor");
		
		m_cursorY--;
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Down, 250)) {
		SoundEffect::play("menuCursor");
		
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
	
	if(Keyboard::isKeyPressedOnce(Keyboard::A)) {
		SoundEffect::play("menuSelect");
		
		Player::player.inventory().setWeaponA(Vector2i(m_cursorX, m_cursorY));
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::B)) {
		SoundEffect::play("menuSelect");
		
		Player::player.inventory().setWeaponB(Vector2i(m_cursorX, m_cursorY));
	}
}

void Menu::draw() {
	m_background.draw(0, 16);
	
	m_cursor.draw(22 + m_cursorX * 32, 25 + m_cursorY * 24);
	
	for(u8 y = 0 ; y < 4 ; y++) {
		for(u8 x = 0 ; x < 4 ; x++) {
			Weapon *currentWeapon = Player::player.inventory().getWeaponByPosition(Vector2i(x, y));
			
			if(currentWeapon != nullptr) {
				currentWeapon->icon().draw(22 + x * 32, 23 + y * 24);
			}
		}
	}
}

