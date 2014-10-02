/*
 * =====================================================================================
 *
 *       Filename:  Inventory.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/10/2014 18:31:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Inventory.hpp"

Inventory::Inventory() {
	
}

Inventory::~Inventory() {
}

void Inventory::addWeapon(u8 weaponID, Vector2i position) {
	m_weapons.push_back(std::make_pair(weaponID, position));
}

