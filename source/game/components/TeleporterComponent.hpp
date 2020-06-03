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
#ifndef TELEPORTERCOMPONENT_HPP_
#define TELEPORTERCOMPONENT_HPP_

#include "Direction.hpp"

class TeleporterComponent {
	public:
		void setDestination(u16 area, u16 mapX, u16 mapY, u16 playerX, u16 playerY, Direction playerDirection) {
			m_area = area;

			m_mapX = mapX;
			m_mapY = mapY;

			m_playerX = playerX;
			m_playerY = playerY;

			m_playerDirection = playerDirection;
		}

		u16 area() const { return m_area; }

		u16 mapX() const { return m_mapX; }
		u16 mapY() const { return m_mapY; }

		u16 playerX() const { return m_playerX; }
		u16 playerY() const { return m_playerY; }

		Direction playerDirection() const { return m_playerDirection; }

	private:
		u16 m_area = 0;

		u16 m_mapX = 0;
		u16 m_mapY = 0;

		u16 m_playerX = 0;
		u16 m_playerY = 0;

		Direction m_playerDirection = Direction::None;
};

#endif // TELEPORTERCOMPONENT_HPP_
