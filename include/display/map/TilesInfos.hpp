/*
 * =====================================================================================
 *
 *       Filename:  TilesInfos.hpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 13:43:27
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TILESINFOS_HPP_
#define TILESINFOS_HPP_

#include "Types.hpp"

namespace TilesInfos {
	enum SubTileType : u8 {
		Passable		= 0,
		NonPassable		= 1
	};
	
	static const u16 infos[6][4] = {
		// Tile 0: Passable
		{0, 0,
		 0, 0},
		
		// Tile 1: Non passable
		{1, 1,
		 1, 1},
		
		// Tile 2: Half bottom passable
		{1, 1,
		 0, 0},
		
		// Tile 3: Half top passable
		{0, 0,
		 1, 1},
		
		// Tile 4: Half right passable
		{1, 0,
		 1, 0},
		
		// Tile 5; Half left passable
		{0, 1,
		 0, 1},
	};
}

#endif // TILESINFOS_HPP_
