/*
 * =====================================================================================
 *
 *       Filename:  WeaponManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/10/2014 18:45:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Sword.hpp"
#include "WeaponManager.hpp"

std::vector<Weapon*> WeaponManager::weapons;

void WeaponManager::init() {
	weapons.push_back(new Sword);
}

void WeaponManager::free() {
	while(weapons.size() != 0) {
		delete weapons.back();
		weapons.pop_back();
	}
}

Weapon *WeaponManager::getWeaponByID(u8 id) {
	return weapons[id];
}

