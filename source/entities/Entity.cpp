/*
 * =====================================================================================
 *
 *       Filename:  Entity.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:11:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Entity.hpp"
#include "MapHelper.hpp"

Entity::Entity() {
}

Entity::Entity(s16 x, s16 y, u16 width, u16 height) {
	load(x, y, width, height);
}

Entity::~Entity() {
}

void Entity::load(s16 x, s16 y, u16 width, u16 height) {
	m_x = x;
	m_y = y;
	
	m_width = width;
	m_height = height;
	
	m_vx = 0;
	m_vy = 0;
	
	m_hitbox = IntRect(0, 0, m_width, m_height);
}

bool Entity::inCollisionWith(Entity *e) {
	IntRect hitbox1(m_x + m_hitbox.x + m_vx, m_y + m_hitbox.y + m_vy, m_hitbox.width, m_hitbox.height);
	IntRect hitbox2(e->m_x + e->m_hitbox.x + e->m_vx, e->m_y + e->m_hitbox.y + e->m_vy, e->m_hitbox.width, e->m_hitbox.height);
	return hitbox1.intersects(hitbox2);
}

bool Entity::onTile(u16 tile) {
	return (MapHelper::isTile(m_x + 6, m_y + 11, tile) 
		&&  MapHelper::isTile(m_x + 7, m_y + 11, tile) 
		&&  MapHelper::isTile(m_x + 6, m_y + 12, tile) 
		&&  MapHelper::isTile(m_x + 7, m_y + 12, tile));
}

