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
#ifndef BUTTONCOMPONENT_HPP_
#define BUTTONCOMPONENT_HPP_

#include <tuple>
#include <vector>

#include <gk/core/IntTypes.hpp>

class TileChange {
	public:
		TileChange(u16 _tileX, u16 _tileY, s16 _oldID, s16 _newID)
			: tileX(_tileX), tileY(_tileY), oldID(_oldID), newID(_newID) {}

		u16 tileX;
		u16 tileY;

		s16 oldID;
		u16 newID;
};

class ButtonComponent {
	public:
		void addTileChange(u16 tileX, u16 tileY, u16 newID);

		void pressedAction(u16 buttonTileX, u16 buttonTileY);
		void releasedAction(u16 buttonTileX, u16 buttonTileY);

		const std::vector<TileChange> &tileChanges() const { return m_tileChanges; }

	private:
		bool m_pressed = true;

		std::vector<TileChange> m_tileChanges;
};

#endif // BUTTONCOMPONENT_HPP_
