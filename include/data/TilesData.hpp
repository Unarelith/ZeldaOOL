/*
 * =====================================================================================
 *
 *       Filename:  TilesData.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/08/2014 19:44:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TILESDATA_HPP_
#define TILESDATA_HPP_

#include "Types.hpp"

#define TILE_NB 15

namespace TilesData {
	extern u16 infos[TILE_NB][4];
	
	enum SubTileType {
		Passable		= 0,
		NonPassable		= 1,
		ChangeMap		= 2
	};
	
	enum TileType {
		SlowingTile		= 11,
		LowGrassTile	= 12,
		LowWaterTile	= 13,
		GrassTile		= 14
	};
}

#endif // TILESDATA_HPP_
