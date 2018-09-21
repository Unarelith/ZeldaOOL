/*
 * =====================================================================================
 *
 *       Filename:  TilesInfos.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 22:21:37
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILESINFOS_HPP_
#define TILESINFOS_HPP_

#include "IntTypes.hpp"

#define TILE_NB 19

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
		OpenedChest		= 17,
		Stone			= 18,
	};
}

#endif // TILESINFOS_HPP_
