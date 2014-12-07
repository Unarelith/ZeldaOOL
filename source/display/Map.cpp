/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/2014 03:46:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "ResourceHandler.hpp"

Map::Map() {
}

Map::Map(std::string filename, std::string tilesetName, u16 area, u16 x, u16 y, u16 zoneID) {
	load(filename, tilesetName, area, x, y, zoneID);
}

Map::~Map() {
}

void Map::load(std::string filename, std::string tilesetName, u16 area, u16 x, u16 y, u16 zoneID) {
	AnimatedMap::load(filename, tilesetName);
	
	m_area = area;
	
	m_x = x;
	m_y = y;
	
	m_zoneID = zoneID;
}

Map &Map::getMap(u16 area, u16 x, u16 y) {
	std::string mapName = std::to_string(area) + "-" + std::to_string(x) + "-" + std::to_string(y);
	return ResourceHandler::getInstance().get<Map>(mapName);
}

