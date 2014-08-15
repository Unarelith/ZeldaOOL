/*
 * =====================================================================================
 *
 *       Filename:  Character.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/08/2014 19:07:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Character.hpp"

Character::Character(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction) : Sprite(filename, width, height), Entity(x, y, width, height) {
	m_direction = direction;
}

Character::~Character() {
}

void Character::mapCollisions() {
	
}

void Character::draw() {
	playAnimation(m_x, m_y, m_direction);
}

