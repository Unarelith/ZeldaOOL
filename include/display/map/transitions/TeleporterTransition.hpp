/*
 * =====================================================================================
 *
 *       Filename:  TeleporterTransition.hpp
 *
 *    Description:  
 *
 *        Created:  05/10/2014 21:52:46
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TELEPORTERTRANSITION_HPP_
#define TELEPORTERTRANSITION_HPP_

#include "Direction.hpp"
#include "Map.hpp"
#include "RectangleShape.hpp"
#include "Transition.hpp"

class TeleporterTransition : public Transition {
	public:
		TeleporterTransition(u16 area, Vector2u16 map, Vector2f playerPosition, Direction playerDirection, bool movePlayer = false);
		
		void update();
		
		void draw();
		
	private:
		Map *m_nextMap;
		
		Vector2f m_playerPosition;
		
		Direction m_playerDirection;
		
		bool m_movePlayer;
		
		Timer m_timer;
		
		RectangleShape m_rect1;
		RectangleShape m_rect2;
};

#endif // TELEPORTERTRANSITION_HPP_
