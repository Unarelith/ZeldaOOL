/*
 * =====================================================================================
 *
 *       Filename:  Character.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:17:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Character.hpp"
#include "MapHelper.hpp"
#include "TilesData.hpp"

Character::Character() {
}

Character::Character(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	load(filename, x, y, width, height, direction);
}

Character::~Character() {
}

void Character::load(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	Sprite::load(filename, width, height);
	Entity::load(x, y, width, height);
	
	m_direction = direction;
}

void Character::draw() {
	playAnimation(m_x, m_y, m_direction);
}

void Character::turn(bool clockwise) {
	switch(m_direction) {
		case Direction::Left:
			m_direction = (clockwise) ? Direction::Up	 : Direction::Down;
			break;
		case Direction::Right:
			m_direction = (clockwise) ? Direction::Down	 : Direction::Up;
			break;
		case Direction::Up:
			m_direction = (clockwise) ? Direction::Right : Direction::Left;
			break;
		case Direction::Down:
			m_direction = (clockwise) ? Direction::Left	 : Direction::Right;
			break;
			
	}
}

void Character::mapCollisions() {
	
}

