/*
 * =====================================================================================
 *
 *       Filename:  TeleporterComponent.hpp
 *
 *    Description:
 *
 *        Created:  22/02/2015 13:47:45
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
