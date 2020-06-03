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
