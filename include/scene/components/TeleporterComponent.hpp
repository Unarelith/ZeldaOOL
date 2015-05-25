/*
 * =====================================================================================
 *
 *       Filename:  TeleporterComponent.hpp
 *
 *    Description:  
 *
 *        Created:  22/02/2015 13:47:45
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TELEPORTERCOMPONENT_HPP_
#define TELEPORTERCOMPONENT_HPP_

#include "Direction.hpp"
#include "Vector2.hpp"

class TeleporterComponent {
	public:
		void setDestination(u16 area, Vector2u16 map, Vector2f playerPosition, Direction playerDirection) {
			m_area = area;
			
			m_map = map;
			
			m_playerPosition = playerPosition;
			
			m_playerDirection = playerDirection;
		}
		
		u16 area() const { return m_area; }
		
		Vector2u16 map() const { return m_map; }
		
		Vector2f playerPosition() const { return m_playerPosition; }
		
		Direction playerDirection() const { return m_playerDirection; }
		
	private:
		u16 m_area = 0;
		
		Vector2u16 m_map = {0, 0};
		
		Vector2f m_playerPosition = {0, 0};
		
		Direction m_playerDirection = Direction::None;
};

#endif // TELEPORTERCOMPONENT_HPP_
