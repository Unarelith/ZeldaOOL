/*
 * =====================================================================================
 *
 *       Filename:  MapObject.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/2014 19:46:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GameState.hpp"
#include "MapObject.hpp"
#include "Player.hpp"

MapObject::MapObject() {
}

MapObject::MapObject(std::string filename, u8 type, u16 frameWidth, u16 frameHeight) {
	load(filename, frameWidth, frameHeight);
}

MapObject::~MapObject() {
}

void MapObject::load(std::string filename, u8 type, u16 frameWidth, u16 frameHeight) {
	Movable::load(filename, frameWidth, frameHeight);
	
	m_type = type;
	
	addCollisionHandler(std::bind(&MapObject::mapObjectsCollisions, this));
}

bool MapObject::inCollisionWith(MapObject &mapObject) {
	sf::FloatRect rect1 = sf::FloatRect(getPosition().x, getPosition().y, m_frameWidth, m_frameHeight);
	sf::FloatRect rect2 = sf::FloatRect(mapObject.getPosition().x, mapObject.getPosition().y, mapObject.m_frameWidth, mapObject.m_frameHeight);
	return rect1.intersects(rect2);
}

void MapObject::mapObjectsCollisions() {
	Map &currentMap = GameState::getInstance().currentMap();
	
	for(auto &it : currentMap.objects()) {
		if(inCollisionWith(*it)) {
			collisionAction(*it);
			it->collisionAction(*this);
		}
	}
	
	if(m_type != Type::Player && inCollisionWith(Player::getInstance())) {
		collisionAction(Player::getInstance());
		Player::getInstance().collisionAction(*this);
	}
}

