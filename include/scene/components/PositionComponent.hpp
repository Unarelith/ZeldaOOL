/*
 * =====================================================================================
 *
 *       Filename:  PositionComponent.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 15:02:57
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef POSITIONCOMPONENT_HPP_
#define POSITIONCOMPONENT_HPP_

#include "Direction.hpp"
#include "Rect.hpp"
#include "Types.hpp"

class PositionComponent {
	public:
		PositionComponent(float _x, float _y, u16 _width, u16 _height)
			: x(_x), y(_y), width(_width), height(_height), hitbox(0, 0, width, height) {}
		
		void updateDirection(float vx, float vy) {
			if(vx < 0) direction = Direction::Left;
			if(vx > 0) direction = Direction::Right;
			if(vy < 0) direction = Direction::Up;
			if(vy > 0) direction = Direction::Down;
		}
		
		void move(float dx, float dy) {
			x += dx;
			y += dy;
		}
		
		float x = 0;
		float y = 0;
		
		u16 width = 0;
		u16 height = 0;
		
		Direction direction = Direction::None;
		
		IntRect hitbox;
};

#endif // POSITIONCOMPONENT_HPP_
