/*
 * =====================================================================================
 *
 *       Filename:  MapObject.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/01/2015 00:42:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "MapObject.hpp"

MapObject::MapObject(const std::string &textureName, u16 width, u16 height) : Sprite(textureName, width, height) {
	m_width = width;
	m_height = height;
	
	m_hitbox.reset(0, 0, m_width, m_height);
}

bool MapObject::inCollisionWith(const MapObject &object) const {
	FloatRect rect1(m_x + m_hitbox.x, m_y + m_hitbox.y, m_hitbox.width, m_hitbox.height);
	FloatRect rect2(object.m_x + object.m_hitbox.x, object.m_y + object.m_hitbox.y, object.m_hitbox.width, object.m_hitbox.height);
	return rect1.intersects(rect2);
}

void MapObject::addCollisionHandler(const std::function<void(void)> &collisionHandler) {
	m_collisionHandlers.push_back(collisionHandler);
}

void MapObject::testCollisions() {
	for(auto &it : m_collisionHandlers) {
		it();
	}
}

