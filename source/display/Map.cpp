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
#include "Player.hpp"
#include "GrassObject.hpp"
#include "Map.hpp"
#include "MapLoader.hpp"
#include "ResourceHandler.hpp"
#include "TilesData.hpp"
#include "Weapon.hpp"
#include "XMLFile.hpp"

Map *Map::currentMap = nullptr;

Map::Map(const std::string &filename, Tileset &tileset, u16 area, u16 x, u16 y) {
	load(filename, tileset, area, x, y);
}

void Map::load(const std::string &filename, Tileset &tileset, u16 area, u16 x, u16 y) {
	AnimatedMap::load(filename, tileset);
	
	m_area = area;
	
	m_x = x;
	m_y = y;
	
	updateTiles();
}

void Map::resetTiles() {
	XMLTileMap::resetTiles();
	
	m_objects.erase(std::remove_if(m_objects.begin(), m_objects.end(),
		            [&](std::unique_ptr<MapObject> &it) {
		                return it->checkType<Collectable>();
		            }), m_objects.end());
	
	for(auto &it : m_objects) {
		it->reset(*this);
	}
}

void Map::updateTile(u16 tileX, u16 tileY, u16 id) {
	AnimatedMap::updateTile(tileX, tileY, id);
	
	u16 x = tileX * m_tileset->tileWidth();
	u16 y = tileY * m_tileset->tileHeight();
	
	if(m_tileset->info()[id] == TilesData::TileType::GrassTile) {
		addObject<GrassObject>(x, y);
	}
	else if(m_tileset->info()[id] == TilesData::TileType::LowGrassTile) {
		addObject<GrassObject>(x, y, true);
	}
}

void Map::update(bool onlyTiles) {
	animateTiles();
	
	if(!onlyTiles) {
		for(auto &it : m_objects) {
			// FIXME: I actually remove the collectables from here
			if(it) it->update();
		}
	}
}

void Map::draw() {
	TileMap::draw();
	
	for(auto &it : m_objects) {
		it->draw();
	}
}

void Map::removeObject(MapObject &object) {
	m_objects.erase(std::remove_if(m_objects.begin(), m_objects.end(),
		            [&](std::unique_ptr<MapObject> &it) {
		                return it.get() == &object;
		            }), m_objects.end());
}

bool Map::objectAtPosition(const MapObject &obj, float x, float y) const {
	return((floor(obj.x() / 8) == floor(x / 8)
	     || floor(obj.x() / 8) == floor(x / 8) - 1)
	    && (floor(obj.y() / 8) == floor(y / 8)
	     || floor(obj.y() / 8) == floor(y / 8) - 1));
}

// FIXME: TO REMOVE, USED IN PLAYER TO GET CHESTOBJECT
MapObject *Map::getObject(float x, float y) {
	for(auto &it : m_objects) {
		if(objectAtPosition(*it, x, y)) {
			return it.get();
		}
	}
	
	return nullptr;
}

void Map::checkCollisionsFor(MapObject *object) {
	for(auto &it : m_objects) {
		MapObject *object2 = (it && it.get() != object) ? it.get() : &Player::player;
		
		if(object->inCollisionWith(*object2)) {
			object->collisionAction(*object2);
			object2->collisionAction(*object);
		}
	}
}

Map &Map::getMap(u16 area, u16 mapX, u16 mapY) {
	return ResourceHandler::getInstance().get<Map>(MapLoader::makeName(area, mapX, mapY));
}

