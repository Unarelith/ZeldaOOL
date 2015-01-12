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
std::vector<std::vector<Map>> MapManager::maps;

void MapManager::init() {
	initTilesets();
	initMaps();
	
	currentMap = &maps[0][0];
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
	
	std::vector<Map> overworld;
	//overworld.emplace_back("data/maps/a1.tmx", &tilesets[0], 0, 0, 0);
	overworld.push_back(std::move(handler.get<Map>("0-0-0")));
	overworld.emplace_back("data/maps/a2.tmx", &tilesets[0], 0, 1, 0);
	overworld.emplace_back("data/maps/b1.tmx", &tilesets[0], 0, 0, 1);
	overworld.emplace_back("data/maps/b2.tmx", &tilesets[0], 0, 1, 1);
	
	std::vector<Map> indoor;
	indoor.emplace_back("data/maps/in1.tmx", &tilesets[1], 1, 0, 0);
	
	std::vector<Map> cave1;
	cave1.emplace_back("data/maps/ca1a1.tmx", &tilesets[2], 2, 0, 0);
	
	maps.push_back(std::move(overworld));
	maps.push_back(std::move(indoor));
	maps.push_back(std::move(cave1));
}

Map *MapManager::getMap(u16 area, u8 mapX, u8 mapY) {
	return &maps[area][mapX + mapY * sqrt(maps[area].size())];
}

