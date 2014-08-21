/*
 * =====================================================================================
 *
 *       Filename:  MapMananger.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/08/2014 20:21:38
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
	tilesets.push_back(Tileset("graphics/tilesets/indoor.png", TilesetsData::indoorInfo));
	tilesets.push_back(Tileset("graphics/tilesets/underground.png", TilesetsData::undergroundInfo));
}

void MapManager::initMaps() {
	std::vector<Map> overworld;
	overworld.push_back(Map("data/maps/a1.tmx", tilesets[0], 0, 0, 0));
	overworld.push_back(Map("data/maps/a2.tmx", tilesets[0], 0, 1, 0));
	overworld.push_back(Map("data/maps/b1.tmx", tilesets[0], 0, 0, 1));
	overworld.push_back(Map("data/maps/b2.tmx", tilesets[0], 0, 1, 1));
	
	std::vector<Map> indoor;
	indoor.push_back(Map("data/maps/in1.tmx", tilesets[1], 1, 0, 0));
	
	maps.push_back(std::vector<Map>(overworld));
	maps.push_back(std::vector<Map>(indoor));
}

