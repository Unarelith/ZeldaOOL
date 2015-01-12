/*
 * =====================================================================================
 *
 *       Filename:  MapLoader.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2015 15:05:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "MapLoader.hpp"
#include "MapManager.hpp"

void MapLoader::load(const std::string &, ResourceHandler &handler) {
	handler.add<Map>("0-0-0", "data/maps/a1.tmx", &MapManager::tilesets[0], 0, 0, 0);
}

