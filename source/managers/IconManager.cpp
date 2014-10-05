/*
 * =====================================================================================
 *
 *       Filename:  IconManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2014 13:50:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "IconManager.hpp"

std::vector<Image> IconManager::weapons;

void IconManager::init() {
	weapons.push_back(Image("graphics/icons/swordL1.png"));
}

Image &IconManager::getWeaponIconByID(u8 id) {
	return weapons[id];
}

