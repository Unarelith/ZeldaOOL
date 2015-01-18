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

std::vector<std::unique_ptr<Weapon>> WeaponManager::weapons;

void WeaponManager::init() {
	weapons.emplace_back(new Sword);
}

Weapon *WeaponManager::getWeaponByID(u8 id) {
	return weapons[id].get();
}

