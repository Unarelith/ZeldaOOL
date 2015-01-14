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
#include "CharacterManager.hpp"
#include "Keyboard.hpp"
#include "Weapon.hpp"

Weapon::Weapon(std::string name, u16 width, u16 height) : Sprite(name, width, height), Entity(0, 0, width, height), m_player(CharacterManager::player) {
	// TODO: TO CHANGE LATER, WORKS ONLY FOR SWORD
	m_icon.load(name + "L1");
	
	m_strength = 1;
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

