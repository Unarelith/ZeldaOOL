/*
 * =====================================================================================
 *
 *       Filename:  MapObject.cpp
 *
 *    Description:  
 *
 *        Created:  18/01/2015 00:42:29
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "TilesInfos.hpp"

MapObject::MapObject(float x, float y, u16 width, u16 height) {
	load(x, y, width, height);
}

MapObject::MapObject(const std::string &textureName, float x, float y, u16 width, u16 height) {
	load(textureName, x, y, width, height);
}

void MapObject::load(float x, float y, u16 width, u16 height) {
	m_x = x;
	m_y = y;
	
	m_width = width;
	m_height = height;
	
	m_hitbox.reset(0, 0, m_width, m_height);
	
	m_grassEffect.load("animations-grassEffect");
	
	m_lowWaterEffect.load("animations-lowWaterEffect", 16, 16);
	m_lowWaterEffect.addAnimation({0, 1, 2}, 100);
}

void MapObject::load(const std::string &textureName, float x, float y, u16 width, u16 height) {
	Sprite::load(textureName, width, height);
	
	load(x, y, width, height);
}

bool MapObject::inCollisionWith(MapObject &object) {
	FloatRect rect1(m_x + m_vx + m_hitbox.x,
	                m_y + m_vy + m_hitbox.y,
	                m_hitbox.width, m_hitbox.height);
	
	FloatRect rect2(object.m_x + object.m_vx,
	                object.m_y + object.m_vy,
	                object.m_hitbox.width, object.m_hitbox.height);
	
	if(hasAnimations()) {
		rect1.x += currentAnimation().currentPosition().first;
		rect1.y += currentAnimation().currentPosition().second;
	}
	
	if(object.hasAnimations()) {
		rect2.x += object.currentAnimation().currentPosition().first;
		rect2.y += object.currentAnimation().currentPosition().second;
	}
	
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

bool MapObject::onTile(u16 tile) const {
	return (Map::currentMap->isTile(m_x + 6, m_y + 11, tile) 
	    &&  Map::currentMap->isTile(m_x + 7, m_y + 11, tile) 
	    &&  Map::currentMap->isTile(m_x + 6, m_y + 12, tile) 
	    &&  Map::currentMap->isTile(m_x + 7, m_y + 12, tile));
}

void MapObject::draw() {
	if(onTile(TilesInfos::TileType::LowGrassTile)) {
		m_grassEffect.draw(m_x, m_y);
	}
	
	if(onTile(TilesInfos::TileType::LowWaterTile)) {
		m_lowWaterEffect.playAnimation(m_x, m_y + 8, 0);
	}
}

