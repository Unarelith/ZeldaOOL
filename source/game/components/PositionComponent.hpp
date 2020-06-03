/*
 * =====================================================================================
 *
 *       Filename:  PositionComponent.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:22:51
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef POSITIONCOMPONENT_HPP_
#define POSITIONCOMPONENT_HPP_

#include <gk/core/Rect.hpp>
#include <gk/core/Vector2.hpp>

#include "Direction.hpp"

class PositionComponent : public gk::FloatRect {
	public:
		PositionComponent() = default;

		PositionComponent(float x, float y, float width, float height, Direction _direction = Direction::None)
			: gk::FloatRect(x, y, width, height), direction(_direction) {
		}

		PositionComponent(const gk::Vector2f &position, const gk::Vector2f &size)
			: gk::FloatRect(position, size) {
		}

		void updateDirection(const gk::Vector2f &v) {
			if(v.x < 0) direction = Direction::Left;
			if(v.x > 0) direction = Direction::Right;
			if(v.y < 0) direction = Direction::Up;
			if(v.y > 0) direction = Direction::Down;
		}

		gk::Vector2i getMovementFromDirection() {
			gk::Vector2i v;
			v.x = (direction == Direction::Left ? -1 : (direction == Direction::Right ? 1 : 0));
			v.y = (direction == Direction::Up ? -1 : (direction == Direction::Down ? 1 : 0));
			return v;
		}

		gk::Vector2i getFrontTile() {
			gk::Vector2i v;
			v.x = (x + sizeX / 2) / 16;
			v.y = (y + sizeY / 2) / 16;
			v += getMovementFromDirection();
			return v;
		}

		Direction direction = Direction::None;
};

#endif // POSITIONCOMPONENT_HPP_
