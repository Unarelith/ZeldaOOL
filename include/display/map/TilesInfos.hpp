/*
 * =====================================================================================
 *
 *       Filename:  TilesInfos.hpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 13:43:27
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TILESINFOS_HPP_
#define TILESINFOS_HPP_

#include "Types.hpp"

#define TILE_NB 18

namespace TilesInfos {
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

#endif // TILESINFOS_HPP_
