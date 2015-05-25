/*
 * =====================================================================================
 *
 *       Filename:  PositionComponent.hpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:22:51
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef POSITIONCOMPONENT_HPP_
#define POSITIONCOMPONENT_HPP_

#include "Direction.hpp"
#include "Rect.hpp"
#include "Vector2.hpp"

class PositionComponent : public FloatRect {
	public:
		PositionComponent() = default;
		
		PositionComponent(float x, float y, float width, float height)
			: FloatRect(x, y, width, height) {
		}
		
		PositionComponent(Vector2f position, float width, float height)
			: FloatRect(position, width, height) {
		}
		
		void updateDirection(Vector2f v) {
			if(v.x < 0) direction = Direction::Left;
			if(v.x > 0) direction = Direction::Right;
			if(v.y < 0) direction = Direction::Up;
			if(v.y > 0) direction = Direction::Down;
		}
		
		Direction direction = Direction::None;
};

#endif // POSITIONCOMPONENT_HPP_
