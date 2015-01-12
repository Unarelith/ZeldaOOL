/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 19:04:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "Config.hpp"
#include "CharacterManager.hpp"
#include "GrassObject.hpp"
#include "MapManager.hpp"
#include "TilesData.hpp"
#include "Weapon.hpp"
#include "XMLFile.hpp"

Map::Map() {
}

//Map::Map(const Map &map) : AnimatedMap() {
//	load(map.m_filename, map.m_tileset, map.m_area, map.m_x, map.m_y);
//}

Map::Map(Map &&map) : AnimatedMap(std::move(map)) {
	m_filename = map.m_filename;
	
	m_area = map.m_area;
	
	m_x = map.m_x;
	m_y = map.m_y;
	
	std::swap(m_baseData, map.m_baseData);
	std::swap(m_data, map.m_data);
	
	std::swap(m_objects, map.m_objects);
	std::swap(m_collectables, map.m_collectables);
	std::swap(m_enemies, map.m_enemies);
}

Map::Map(std::string filename, Tileset *tileset, u16 area, u16 x, u16 y) {
	load(filename, tileset, area, x, y);
}

Map::~Map() {
	while(m_objects.size() != 0) {
		delete m_objects.back();
		m_objects.pop_back();
	}
	
	while(m_collectables.size() != 0) {
		delete m_collectables.back();
		m_collectables.pop_back();
	}
	
	while(m_enemies.size() != 0) {
		delete m_enemies.back();
		m_enemies.pop_back();
	}
}

#include "Debug.hpp"

void Map::load(std::string filename, Tileset *tileset, u16 area, u16 x, u16 y) {
	m_filename = filename;
	
	m_area = area;
	
	m_x = x;
	m_y = y;
	
	XMLFile doc(filename);
	
	XMLElement *mapElement = doc.FirstChildElement("map").ToElement();
	
	m_width = mapElement->IntAttribute("width");
	m_height = mapElement->IntAttribute("height");
	
	XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		m_baseData.push_back(tileElement->IntAttribute("gid") - 1);
		
		tileElement = tileElement->NextSiblingElement("tile");
	}
	
	m_data = m_baseData;
	
	AnimatedMap::load(*tileset, m_width, m_height);
	
	m_tileset->tileWidth = mapElement->IntAttribute("tilewidth");
	m_tileset->tileHeight = mapElement->IntAttribute("tileheight");
	
	updateTiles();
}

void Map::resetTiles() {
	m_data = m_baseData;
	
	for(auto &it : m_objects) {
		it->resetTiles(this);
	}
	
	for(auto &it : m_enemies) {
		it->reset();
	}
}

void Map::updateTiles() {
	for(u16 tileY = 0 ; tileY < m_height ; tileY++) {
		for(u16 tileX = 0 ; tileX < m_width ; tileX++) {
			updateTile(tileX, tileY, getTile(tileX, tileY));
			
			u16 x = tileX * m_tileset->tileWidth;
			u16 y = tileY * m_tileset->tileHeight;
			
			if(m_tileset->info[getTile(tileX, tileY)] == TilesData::TileType::GrassTile) {
				addObject(new GrassObject(x, y));
			}
			else if(m_tileset->info[getTile(tileX, tileY)] == TilesData::TileType::LowGrassTile) {
				addObject(new GrassObject(x, y, true));
			}
		}
	}
}

void Map::update(bool onlyTiles) {
	animateTiles();
	
	if(!onlyTiles) {
		for(auto &it : m_collectables) {
			it->update();
		}
		
		for(auto &it : m_enemies) {
			if(CharacterManager::player.inCollisionWith(it)
			&& !it->isDead()) {
				s16 vx = CharacterManager::player.x() - it->x();
				s16 vy = CharacterManager::player.y() - it->y();
				
				if(vx != 0) vx /= abs(vx);
				if(vy != 0) vy /= abs(vy);
				
				CharacterManager::player.setVelocity(vx, vy);
				CharacterManager::player.hurt(it->strength());
			}
			
			if(CharacterManager::player.inventory().weaponA()) {
				CharacterManager::player.inventory().weaponA()->testCollisionWith(it);
			}
			
			if(CharacterManager::player.inventory().weaponB()) {
				CharacterManager::player.inventory().weaponB()->testCollisionWith(it);
			}
			
			it->update();
		}
	}
}

void Map::draw() {
	TileMap::draw();
	
	for(auto &it : m_collectables) {
		it->draw();
	}
	
	for(auto &it : m_enemies) {
		it->draw();
	}
}

void Map::addObject(Object *obj) {
	for(u16 i = 0 ; i < m_objects.size() ; i++) {
		if(m_objects[i]->x() == obj->x() && m_objects[i]->y() == obj->y()) {
			delete m_objects[i];
			m_objects.erase(m_objects.begin() + i);
			
			break;
		}
	}
	
	m_objects.push_back(obj);
}

void Map::addCollectable(Collectable *collectable) {
	m_collectables.push_back(collectable);
}

void Map::addEnemy(Enemy *enemy) {
	m_enemies.push_back(enemy);
}

void Map::removeCollectable(Collectable *collectable) {
	for(u16 i = 0 ; i < m_collectables.size() ; i++) {
		if(m_collectables[i] == collectable) {
			delete m_collectables[i];
			m_collectables.erase(m_collectables.begin() + i);
			
			break;
		}
	}
}

bool Map::objectAtPosition(Object *obj, float x, float y) {
	return((floor(obj->x() / 8) == floor(x / 8)
		 || floor(obj->x() / 8) == floor(x / 8) - 1)
		&& (floor(obj->y() / 8) == floor(y / 8)
		 || floor(obj->y() / 8) == floor(y / 8) - 1));
}

void Map::sendEvent(EventType event, Entity *e, Vector2i offsets) {
	if(!e) e = &CharacterManager::player;
	
	for(auto &it : m_objects) {
		if(objectAtPosition(it, e->x() + offsets.x, e->y() + offsets.y)) {
			it->onEvent(event);
			
			break;
		}
	}
}

