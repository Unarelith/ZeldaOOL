/*
 * =====================================================================================
 *
 *       Filename:  Character.cpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:17:29
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Character.hpp"
#include "Map.hpp"

Character::Character(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	load(filename, x, y, width, height, direction);
}

void Character::load(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	Movable::load(filename, x, y, width, height);
	
	m_direction = direction;
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
	if(m_vy != 0) {
		if (!Map::currentMap->passable(m_x + m_hitbox.x,					m_y + m_hitbox.y + m_vy)
		||  !Map::currentMap->passable(m_x + m_hitbox.x + m_hitbox.width, m_y + m_hitbox.y + m_vy)
		||  !Map::currentMap->passable(m_x + m_hitbox.x,					m_y + m_hitbox.y + m_vy + m_hitbox.height)
		||  !Map::currentMap->passable(m_x + m_hitbox.x + m_hitbox.width, m_y + m_hitbox.y + m_vy + m_hitbox.height)) {
			if (!Map::currentMap->passable(m_x + m_hitbox.x + m_hitbox.width, m_y + m_hitbox.y + m_vy)
			&&	 Map::currentMap->passable(m_x + m_hitbox.x,					m_y + m_hitbox.y + m_vy)) {
				m_vx = -1;
			}
			
			if (!Map::currentMap->passable(m_x + m_hitbox.x,					m_y + m_hitbox.y + m_vy)
			&&   Map::currentMap->passable(m_x + m_hitbox.x + m_hitbox.width, m_y + m_hitbox.y + m_vy)) {
				m_vx = 1;
			}
			
			if (!Map::currentMap->passable(m_x + m_hitbox.x + m_hitbox.width, m_y + m_hitbox.y + m_hitbox.height + m_vy)
			&&	 Map::currentMap->passable(m_x + m_hitbox.x,					m_y + m_hitbox.y + m_hitbox.height + m_vy)) {
				m_vx = -1;
			}
			
			if (!Map::currentMap->passable(m_x + m_hitbox.x,					m_y + m_hitbox.y + m_hitbox.height + m_vy)
			&&   Map::currentMap->passable(m_x + m_hitbox.x + m_hitbox.width, m_y + m_hitbox.y + m_hitbox.height + m_vy)) {
				m_vx = 1;
			}
			
			mapCollisionAction(0, m_vy);
		}
	}
	
	if(m_vx != 0) {
		if (!Map::currentMap->passable(m_x + m_hitbox.x + m_vx,				   m_y + m_hitbox.y)
		||  !Map::currentMap->passable(m_x + m_hitbox.x + m_vx + m_hitbox.width, m_y + m_hitbox.y)
		||  !Map::currentMap->passable(m_x + m_hitbox.x + m_vx,				   m_y + m_hitbox.y + m_hitbox.height)
		||  !Map::currentMap->passable(m_x + m_hitbox.x + m_vx + m_hitbox.width, m_y + m_hitbox.y + m_hitbox.height)) {
			if (!Map::currentMap->passable(m_x + m_hitbox.x + m_vx, m_y + m_hitbox.y + m_hitbox.height)
			&&	 Map::currentMap->passable(m_x + m_hitbox.x + m_vx, m_y + m_hitbox.y)) {
				m_vy = -1;
			}
			
			if (!Map::currentMap->passable(m_x + m_hitbox.x + m_vx, m_y + m_hitbox.y)
			&&   Map::currentMap->passable(m_x + m_hitbox.x + m_vx, m_y + m_hitbox.y + m_hitbox.height)) {
				m_vy = 1;
			}
			
			if (!Map::currentMap->passable(m_x + m_hitbox.x + m_hitbox.width + m_vx, m_y + m_hitbox.y + m_hitbox.height)
			&&	 Map::currentMap->passable(m_x + m_hitbox.x + m_hitbox.width + m_vx, m_y + m_hitbox.y)) {
				m_vy = -1;
			}
			
			if (!Map::currentMap->passable(m_x + m_hitbox.x + m_hitbox.width + m_vx, m_y + m_hitbox.y)
			&&   Map::currentMap->passable(m_x + m_hitbox.x + m_hitbox.width + m_vx, m_y + m_hitbox.y + m_hitbox.height)) {
				m_vy = 1;
			}
			
			mapCollisionAction(m_vx, 0);
		}
	}
}

void Character::mapCollisionAction(float vx, float vy) {
	if(vx != 0) { m_vx = 0; m_blocked = true; }
	if(vy != 0) { m_vy = 0; m_blocked = true; }
}

void Character::updateDirection() {
	if(m_vx < 0) m_direction = Direction::Left;
	if(m_vx > 0) m_direction = Direction::Right;
	if(m_vy < 0) m_direction = Direction::Up;
	if(m_vy > 0) m_direction = Direction::Down;
}

