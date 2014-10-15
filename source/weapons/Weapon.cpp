/*
 * =====================================================================================
 *
 *       Filename:  Weapon.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:26:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "Weapon.hpp"

Weapon::Weapon(std::string filename, u16 width, u16 height) : Sprite(filename, width, height), Entity(0, 0, width, height), m_player(CharacterManager::player) {
	m_playerState = nullptr;
}

Weapon::~Weapon() {
}

bool Weapon::keyPressed() {
	return((Keyboard::isKeyPressed(Keyboard::A)
		 && m_player.inventory().weaponA() == this)
		|| (Keyboard::isKeyPressed(Keyboard::B)
		 && m_player.inventory().weaponB() == this));
}

bool Weapon::keyPressedOnce() {
	return((Keyboard::isKeyPressedOnce(Keyboard::A)
		 && m_player.inventory().weaponA() == this)
		|| (Keyboard::isKeyPressedOnce(Keyboard::B)
		 && m_player.inventory().weaponB() == this));
}

