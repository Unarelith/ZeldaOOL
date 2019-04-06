/*
 * =====================================================================================
 *
 *       Filename:  MovementController.cpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:27:38
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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

		movement.isBlocked.x = false;
		movement.isBlocked.y = false;
	}

	if(object.has<gk::CollisionComponent>()) {
		object.get<gk::CollisionComponent>().checkCollisions(object);
	}

	if(object.has<PositionComponent>() && object.has<gk::MovementComponent>()) {
		auto &position = object.get<PositionComponent>();
		auto &movement = object.get<gk::MovementComponent>();

		movement.isMoving = (movement.v.x || movement.v.y) ? true : false;

		position.left += movement.v.x * movement.speed;
		position.top += movement.v.y * movement.speed;

		movement.v.x = 0;
		movement.v.y = 0;
	}
}

