/*
 * =====================================================================================
 *
 *       Filename:  MapManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:40:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "ResourceHandler.hpp"
#include "MapLoader.hpp"
#include "MapManager.hpp"
#include "TilesetLoader.hpp"

Map *MapManager::currentMap = nullptr;

void MapManager::init() {
	ResourceHandler::getInstance().addType("data/config/tilesets.xml", TilesetLoader());
	ResourceHandler::getInstance().addType("data/config/maps.xml", MapLoader());
	
	currentMap = &getMap(0, 0, 0);
}

Map &MapManager::getMap(u16 area, u16 mapX, u16 mapY) {
	return ResourceHandler::getInstance().get<Map>(MapLoader::makeName(area, mapX, mapY));
}

