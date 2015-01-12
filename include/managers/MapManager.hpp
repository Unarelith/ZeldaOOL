/*
 * =====================================================================================
 *
 *       Filename:  MapManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:40:37
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
	
	Map &getMap(u16 area, u16 mapX, u16 mapY);
	
	extern Map *currentMap;
	
	extern std::vector<Tileset> tilesets;
}

#endif // MAPMANAGER_HPP_
