/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.hpp
 *
 *    Description:
 *
 *        Created:  18/01/2015 02:00:46
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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

