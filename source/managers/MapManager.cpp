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
#include "TilesetsData.hpp"
#include "MapManager.hpp"

Map *MapManager::currentMap = nullptr;

std::vector<Tileset> MapManager::tilesets;

void MapManager::init() {
	initTilesets();
	initMaps();
	
	currentMap = &getMap(0, 0, 0);
}

void MapManager::initTilesets() {
	tilesets.push_back(Tileset("graphics/tilesets/plain.png", TilesetsData::plainInfo));
	tilesets.back().addAnimation({64, 65, 66, 67}, 250);
	
	tilesets.push_back(Tileset("graphics/tilesets/indoor.png", TilesetsData::indoorInfo));
	
	tilesets.push_back(Tileset("graphics/tilesets/underground.png", TilesetsData::undergroundInfo));
}

#include "ResourceHandler.hpp"
#include "MapLoader.hpp"

void MapManager::initMaps() {
	ResourceHandler &handler = ResourceHandler::getInstance();
	handler.addType("data/config/maps.xml", MapLoader());
}

Map &MapManager::getMap(u16 area, u16 mapX, u16 mapY) {
	return ResourceHandler::getInstance().get<Map>(MapLoader::makeName(area, mapX, mapY));
}

