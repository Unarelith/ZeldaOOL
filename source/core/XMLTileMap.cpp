/*
 * =====================================================================================
 *
 *       Filename:  XMLTileMap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/01/2015 22:34:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "XMLFile.hpp"
#include "XMLTileMap.hpp"

XMLTileMap::XMLTileMap(const std::string &filename) {
	load(filename);
}

void XMLTileMap::load(const std::string &filename) {
	XMLFile doc(filename);
	
	XMLElement *mapElement = doc.FirstChildElement("map").ToElement();
	
	m_width = mapElement->IntAttribute("width");
	m_height = mapElement->IntAttribute("height");
	
	XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		s16 tileID = tileElement->IntAttribute("gid") - 1;
		m_baseData.push_back((tileID >= 0) ? tileID : 0);
		
		tileElement = tileElement->NextSiblingElement("tile");
	}
	
	m_data = m_baseData;
}

void XMLTileMap::resetTiles() {
	m_data = m_baseData;
}

u16 XMLTileMap::getTile(u16 tileX, u16 tileY) {
	if(tileX + tileY * m_width < m_width * m_height) {
		return m_data[tileX + tileY * m_width];
	} else {
		return 0;
	}
}

