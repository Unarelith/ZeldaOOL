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
 *        Company:  
 *
 * =====================================================================================
 */
#include "Player.hpp"
#include "Keyboard.hpp"
#include "Weapon.hpp"

Weapon::Weapon(const std::string &textureName, u8 level, u16 width, u16 height) : Movable(textureName, 0, 0, width, height), m_player(Player::player) {
	m_level = level;
	
	std::string weaponName = textureName.substr(textureName.find_first_of('-') + 1);
	if(m_level > 0) weaponName += "L" + std::to_string(m_level);
	
	m_icon.load(std::string("icons-") + weaponName);
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

