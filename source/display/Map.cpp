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
#include "Map.hpp"
#include "MapLoader.hpp"
#include "ResourceHandler.hpp"
#include "TilesData.hpp"
#include "Weapon.hpp"
#include "XMLFile.hpp"

Map *Map::currentMap = nullptr;

Map::Map(std::string filename, Tileset &tileset, u16 area, u16 x, u16 y) {
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

void Map::load(std::string filename, Tileset &tileset, u16 area, u16 x, u16 y) {
	AnimatedMap::load(filename, tileset);
	
	m_area = area;
	
	m_x = x;
	m_y = y;
	
	updateTiles();
}

void Map::resetTiles() {
	XMLTileMap::resetTiles();
	
	for(auto &it : m_objects) {
		it->resetTiles(this);
	}
	
	for(auto &it : m_enemies) {
		it->reset();
	}
}

void Map::updateTile(u16 tileX, u16 tileY, u16 id) {
	AnimatedMap::updateTile(tileX, tileY, id);
	
	u16 x = tileX * m_tileset->tileWidth();
	u16 y = tileY * m_tileset->tileHeight();
	
	if(m_tileset->info()[id] == TilesData::TileType::GrassTile) {
		addObject(new GrassObject(x, y));
	}
	else if(m_tileset->info()[id] == TilesData::TileType::LowGrassTile) {
		addObject(new GrassObject(x, y, true));
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

Map &Map::getMap(u16 area, u16 mapX, u16 mapY) {
	return ResourceHandler::getInstance().get<Map>(MapLoader::makeName(area, mapX, mapY));
}

