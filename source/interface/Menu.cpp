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
#include "Menu.hpp"
#include "Player.hpp"
#include "Weapon.hpp"

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
	
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		AudioPlayer::playEffect("menuSelect");
		
		auto &newWeaponA = Player::player.inventory().getWeapon(m_cursorX, m_cursorY);
		Player::player.inventory().setWeaponA(newWeaponA);
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::B)) {
		AudioPlayer::playEffect("menuSelect");
		
		auto &newWeaponB = Player::player.inventory().getWeapon(m_cursorX, m_cursorY);
		Player::player.inventory().setWeaponB(newWeaponB);
	}
}

void Menu::draw() {
	m_background.draw(0, 16);
	
	m_cursor.draw(22 + m_cursorX * 32, 25 + m_cursorY * 24);
	
	for(u8 y = 0 ; y < 4 ; y++) {
		for(u8 x = 0 ; x < 4 ; x++) {
			auto &currentWeapon = Player::player.inventory().getWeapon(x, y);
			
			if(currentWeapon) {
				currentWeapon->icon().draw(22 + x * 32, 23 + y * 24);
			}
		}
	}
}

