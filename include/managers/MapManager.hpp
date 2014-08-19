/*
 * =====================================================================================
 *
 *       Filename:  MapManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/08/2014 20:21:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MAPMANAGER_HPP_
#define MAPMANAGER_HPP_

#include <vector>

#include "Map.hpp"

namespace MapManager {
	void init();
	
	void initTilesets();
	void initMaps();
	
	extern Map *currentMap;
	
	extern std::vector<Tileset> tilesets;
	extern std::vector<std::vector<Map>> maps;
}

#endif // MAPMANAGER_HPP_
