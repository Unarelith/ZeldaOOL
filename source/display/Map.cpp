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
#include "Map.hpp"
#include "XMLFile.hpp"

Map::Map() {
}

Map::Map(std::string filename, Texture &texture) {
	load(filename, texture);
}

Map::~Map() {
}

bool Map::load(std::string filename, Texture &texture) {
	m_filename = filename;
	
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
	
	TileMap::load(texture, m_width, m_height, m_data.data());
	
	return true;
}

void Map::resetTiles() {
	m_data = m_baseData;
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
	}
}

