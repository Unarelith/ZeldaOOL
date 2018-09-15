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

		PositionComponent(float x, float y, float width, float height, Direction _direction = Direction::None)
			: FloatRect(x, y, width, height), direction(_direction) {
		}

		PositionComponent(const Vector2f &position, const Vector2f &size)
			: FloatRect(position, size) {
		}

		void updateDirection(const Vector2f &v) {
			if(v.x < 0) direction = Direction::Left;
			if(v.x > 0) direction = Direction::Right;
			if(v.y < 0) direction = Direction::Up;
			if(v.y > 0) direction = Direction::Down;
		}

		Vector2i getMovementFromDirection() {
			Vector2i v;
			v.x = (direction == Direction::Left ? -1 : (direction == Direction::Right ? 1 : 0));
			v.y = (direction == Direction::Up ? -1 : (direction == Direction::Down ? 1 : 0));
			return v;
		}

		Vector2i getFrontTile() {
			Vector2i v;
			v.x = (x + width / 2) / 16;
			v.y = (y + height / 2) / 16;
			v += getMovementFromDirection();
			return v;
		}

		Direction direction = Direction::None;
};

#endif // POSITIONCOMPONENT_HPP_
