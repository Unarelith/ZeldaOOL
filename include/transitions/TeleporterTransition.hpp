/*
 * =====================================================================================
 *
 *       Filename:  TeleporterTransition.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 11:07:16
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
		TeleporterTransition(u16 area, u16 mapX, u16 mapY, u16 playerX, u16 playerY, Direction playerDirection);
		
		void update() override;
		
		void draw() override;
		
	private:
		Map *m_nextMap = nullptr;
		
		u16 m_playerX = 0;
		u16 m_playerY = 0;
		
		Direction m_playerDirection = Direction::None;
		
		Timer m_timer;
		
		RectangleShape m_rect1;
		RectangleShape m_rect2;
};

#endif // TELEPORTERTRANSITION_HPP_
