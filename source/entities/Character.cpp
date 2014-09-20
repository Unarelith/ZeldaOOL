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
			if(clockwise) m_direction = Direction::Up;
			else m_direction = Direction::Down;
			break;
		case Direction::Right:
			if(clockwise) m_direction = Direction::Down;
			else m_direction = Direction::Up;
			break;
		case Direction::Up:
			if(clockwise) m_direction = Direction::Right;
			else m_direction = Direction::Left;
			break;
		case Direction::Down:
			if(clockwise) m_direction = Direction::Left;
			else m_direction = Direction::Right;
			break;
	}
}

