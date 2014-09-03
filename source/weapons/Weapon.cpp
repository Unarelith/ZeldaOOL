/*
 * =====================================================================================
 *
 *       Filename:  Weapon.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/09/2014 19:46:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Weapon.hpp"

Weapon::Weapon(std::string filename, u16 width, u16 height) : Sprite(filename, width, height), Entity(0, 0, width, height), m_player(CharacterManager::player) {
}

Weapon::~Weapon() {
}

