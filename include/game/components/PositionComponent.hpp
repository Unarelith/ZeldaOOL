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

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

#include "Direction.hpp"

class PositionComponent : public sf::FloatRect {
	public:
		PositionComponent() = default;

		PositionComponent(float x, float y, float width, float height, Direction _direction = Direction::None)
			: sf::FloatRect(x, y, width, height), direction(_direction) {
		}

		PositionComponent(const sf::Vector2f &position, const sf::Vector2f &size)
			: sf::FloatRect(position, size) {
		}

		void updateDirection(const sf::Vector2f &v) {
			if(v.x < 0) direction = Direction::Left;
			if(v.x > 0) direction = Direction::Right;
			if(v.y < 0) direction = Direction::Up;
			if(v.y > 0) direction = Direction::Down;
		}

		sf::Vector2i getMovementFromDirection() {
			sf::Vector2i v;
			v.x = (direction == Direction::Left ? -1 : (direction == Direction::Right ? 1 : 0));
			v.y = (direction == Direction::Up ? -1 : (direction == Direction::Down ? 1 : 0));
			return v;
		}

		sf::Vector2i getFrontTile() {
			sf::Vector2i v;
			v.x = (left + width / 2) / 16;
			v.y = (top + height / 2) / 16;
			v += getMovementFromDirection();
			return v;
		}

		Direction direction = Direction::None;
};

#endif // POSITIONCOMPONENT_HPP_
