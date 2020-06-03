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
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/MovementComponent.hpp>

#include "MovementController.hpp"
#include "PositionComponent.hpp"

void MovementController::update(gk::SceneObject &object) {
	if(object.has<gk::MovementComponent>()) {
		auto &movement = object.get<gk::MovementComponent>();

		if(movement.movements.size() != 0 && movement.movements.top()) {
			movement.movements.top()->process(object);
		}

		movement.isBlocked = false;
	}

	if(object.has<gk::CollisionComponent>()) {
		object.get<gk::CollisionComponent>().checkCollisions(object);
	}

	if(object.has<PositionComponent>() && object.has<gk::MovementComponent>()) {
		auto &position = object.get<PositionComponent>();
		auto &movement = object.get<gk::MovementComponent>();

		movement.isMoving = (movement.v.x || movement.v.y) ? true : false;

		position.x += movement.v.x * movement.speed;
		position.y += movement.v.y * movement.speed;

		movement.v = 0;
	}
}

