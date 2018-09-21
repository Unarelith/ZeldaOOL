/*
 * =====================================================================================
 *
 *       Filename:  GamePadMovement.hpp
 *
 *    Description:
 *
 *        Created:  18/01/2015 02:00:46
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <cmath>

#include "GamePad.hpp"
#include "GamePadMovement.hpp"

#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

void GamePadMovement::process(SceneObject &object) {
	auto &movementComponent = object.get<MovementComponent>();
	auto &positionComponent = object.get<PositionComponent>();

	if(GamePad::isKeyPressed(GameKey::Left)) {
		movementComponent.v.x = -1;

		if(((!GamePad::isKeyPressed(GameKey::Up) && !GamePad::isKeyPressed(GameKey::Down))
		 || positionComponent.direction == Direction::Right)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Left;
		}
	}
	else if(GamePad::isKeyPressed(GameKey::Right)) {
		movementComponent.v.x = 1;

		if(((!GamePad::isKeyPressed(GameKey::Up) && !GamePad::isKeyPressed(GameKey::Down))
		 || positionComponent.direction == Direction::Left)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Right;
		}
	}

	if(GamePad::isKeyPressed(GameKey::Up)) {
		movementComponent.v.y = -1;

		if(((!GamePad::isKeyPressed(GameKey::Left) && !GamePad::isKeyPressed(GameKey::Right))
		 || positionComponent.direction == Direction::Down)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Up;
		}
	}
	else if(GamePad::isKeyPressed(GameKey::Down)) {
		movementComponent.v.y = 1;

		if(((!GamePad::isKeyPressed(GameKey::Left) && !GamePad::isKeyPressed(GameKey::Right))
		 || positionComponent.direction == Direction::Up)
		&& !movementComponent.isDirectionLocked) {
			positionComponent.direction = Direction::Down;
		}
	}

	if((GamePad::isKeyPressed(GameKey::Left) || GamePad::isKeyPressed(GameKey::Right))
	&& (GamePad::isKeyPressed(GameKey::Up)   || GamePad::isKeyPressed(GameKey::Down))) {
		static const float sqrt2 = sqrt(2);
		movementComponent.v /= sqrt2;
	}

	m_isFinished = true;
}

