/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#include "TilesInfos.hpp"

u16 TilesInfos::infos[TILE_NB][4] = {
	// Tile 0: Passable
	{0, 0,
	 0, 0},

	// Tile 1: Non passable
	{1, 1,
	 1, 1},

	// Tile 2: Change map
	{2, 2,
	 2, 2},

	// Tile 3: Half bottom passable
	{1, 1,
	 0, 0},

	// Tile 4: Half top passable
	{0, 0,
	 1, 1},

	// Tile 5: Half right passable
	{1, 0,
	 1, 0},

	// Tile 6; Half left passable
	{0, 1,
	 0, 1},

	// Tile 7: Half bottom non passable / top change map
	{2, 2,
	 1, 1},

	// Tile 8: Half top non passable / bottom change map
	{1, 1,
	 2, 2},

	// Tile 9: Half right non passable / left change map
	{2, 1,
	 2, 1},

	// Tile 10; Half left non passable / right change map
	{1, 2,
	 1, 2},

	// Tile 11: Slowing tile
	{0, 0,
	 0, 0},

	// Tile 12: Low grass tile
	{0, 0,
	 0, 0},

	// Tile 13: Low water tile
	{0, 0,
	 0, 0},

	// Tile 14: Grass tile
	{1, 1,
	 1, 1},

	// Tile 15: Button
	{0, 0,
	 0, 0},

	// Tile 16: Closed chest
	{1, 1,
	 1, 1},

	// Tile 17: Opened chest
	{1, 1,
	 1, 1},

	// Tile 18: Stone
	{1, 1,
	 1, 1}
};

