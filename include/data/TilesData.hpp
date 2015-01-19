/*
 * =====================================================================================
 *
 *       Filename:  TilesData.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:21:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TILESDATA_HPP_
#define TILESDATA_HPP_

#include "Types.hpp"

#define TILE_NB 18

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
		GrassTile		= 14,
		Button			= 15,
		ClosedChest		= 16,
		OpenedChest		= 17
	};
}

#endif // TILESDATA_HPP_
