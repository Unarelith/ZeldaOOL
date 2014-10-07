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
#include <cmath>

#include "Application.hpp"
#include "Config.hpp"
#include "CharacterManager.hpp"
#include "MapManager.hpp"
#include "XMLFile.hpp"

Map::Map() {
}

Map::Map(const Map &map) {
	load(map.m_filename, map.m_tileset, map.m_area, map.m_x, map.m_y);
}

Map::Map(std::string filename, Tileset *tileset, u16 area, u16 x, u16 y) {
	load(filename, tileset, area, x, y);
}

Map::~Map() {
	while(m_objects.size() != 0) {
		delete m_objects.back();
		m_objects.pop_back();
	}
}

bool Map::load(std::string filename, Tileset *tileset, u16 area, u16 x, u16 y) {
	m_filename = filename;
	
	m_tileset = tileset;
	
	m_area = area;
	
	m_x = x;
	m_y = y;
	
	XMLFile doc(filename);
	
	XMLElement *mapElement = doc.FirstChildElement("map").ToElement();
	
	m_width = mapElement->IntAttribute("width");
	m_height = mapElement->IntAttribute("height");
	
	m_tileWidth = mapElement->IntAttribute("tilewidth");
	m_tileHeight = mapElement->IntAttribute("tileheight");
	
	XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		m_baseData.push_back(tileElement->IntAttribute("gid") - 1);
		
		tileElement = tileElement->NextSiblingElement("tile");
	}
	
	m_data = m_baseData;
	
	TileMap::load(m_tileset->texture, m_width, m_height, m_data.data());
	
	updateTiles();
	
	return true;
}

void Map::resetTiles() {
	for(u16 i = 0 ; i < m_width * m_height ; i++) {
		m_data[i] = m_baseData[i];
	}
	
	for(auto &it : m_objects) {
		it->resetTiles(this);
	}
}

void Map::updateTiles() {
	for(u16 y = 0 ; y < m_height ; y++) {
		for(u16 x = 0 ; x < m_width ; x++) {
			updateTile(x * 16, y * 16, m_data[x + y * m_width]);
			
			for(auto &it : m_tileset->anims) {
				for(auto &n : it.frames) {
					if(getTile(x, y - 1) == n) {
						m_animatedTiles.push_back(AnimatedTile(x, y - 1, n + 1 % it.frames.size(), it));
					}
				}
			}
		}
	}
}

void Map::update() {
	for(auto &it : m_animatedTiles) {
		if(!it.timer.isStarted()) {
			it.timer.start();
		}
		
		if(it.timer.time() >= it.anim.delay) {
			setTile(it.tileX, it.tileY, it.anim.frames[it.nextFrame % it.anim.frames.size()]);
			it.nextFrame++;
			it.timer.reset();
			it.timer.start();
		}
	}
}

void Map::draw() {
	TileMap::draw();
}

u16 Map::getTile(u16 tileX, u16 tileY) {
	if(tileX + tileY * m_width < (u16)m_data.size()) {
		return m_data[tileX + tileY * m_width];
	} else {
		return 0;
	}
}

void Map::setTile(u16 tileX, u16 tileY, u16 tile) {
	if(tileX + tileY * m_width < (u16)m_data.size()) {
		m_data[tileX + tileY * m_width] = tile;
		
		updateTile(tileX * 16, tileY * 16, tile);
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

