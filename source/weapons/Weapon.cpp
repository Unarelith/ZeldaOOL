/*
 * =====================================================================================
 *
 *       Filename:  Weapon.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  24/08/2014 21:08:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Weapon.hpp"

Weapon::Weapon(std::string filename, u16 frameWidth, u16 frameHeight) : Sprite(filename, frameWidth, frameHeight) {
}

Weapon::~Weapon() {
}

