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
#include <cmath>

#include <gk/core/input/GamePad.hpp>
#include <gk/scene/component/MovementComponent.hpp>

#include "GameKey.hpp"
#include "GamePadMovement.hpp"

#include "PositionComponent.hpp"

void GamePadMovement::process(gk::SceneObject &object) {
	auto &movementComponent = object.get<gk::MovementComponent>();
	auto &positionComponent = object.get<PositionComponent>();

	if(gk::GamePad::isKeyPressed(GameKey::Left)) {
		movementComponent.v.x = -1;

		if(((!gk::GamePad::isKeyPressed(GameKey::Up) && !gk::GamePad::isKeyPressed(GameKey::Down))
		 || positionComponent.direction == Direction::Right)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Left;
		}
	}
	else if(gk::GamePad::isKeyPressed(GameKey::Right)) {
		movementComponent.v.x = 1;

		if(((!gk::GamePad::isKeyPressed(GameKey::Up) && !gk::GamePad::isKeyPressed(GameKey::Down))
		 || positionComponent.direction == Direction::Left)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Right;
		}
	}

	if(gk::GamePad::isKeyPressed(GameKey::Up)) {
		movementComponent.v.y = -1;

		if(((!gk::GamePad::isKeyPressed(GameKey::Left) && !gk::GamePad::isKeyPressed(GameKey::Right))
		 || positionComponent.direction == Direction::Down)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Up;
		}
	}
	else if(gk::GamePad::isKeyPressed(GameKey::Down)) {
		movementComponent.v.y = 1;

		if(((!gk::GamePad::isKeyPressed(GameKey::Left) && !gk::GamePad::isKeyPressed(GameKey::Right))
		 || positionComponent.direction == Direction::Up)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Down;
		}
	}

	if((gk::GamePad::isKeyPressed(GameKey::Left) || gk::GamePad::isKeyPressed(GameKey::Right))
	&& (gk::GamePad::isKeyPressed(GameKey::Up)   || gk::GamePad::isKeyPressed(GameKey::Down))) {
		static const float sqrt2 = sqrt(2);
		movementComponent.v /= sqrt2;
	}

	m_isFinished = true;
}

