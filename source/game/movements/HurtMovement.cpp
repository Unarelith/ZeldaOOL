/*
 * =====================================================================================
 *
 *       Filename:  HurtMovement.cpp
 *
 *    Description:
 *
 *        Created:  18/01/2015 18:56:01
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/scene/component/MovementComponent.hpp>

#include "HurtMovement.hpp"

void HurtMovement::process(gk::SceneObject &object) {
	auto &movement = object.get<gk::MovementComponent>();

	if(m_movementCounter < 16) {
		movement.v = {m_vx, m_vy};

		m_movementCounter += movement.speed;
	} else {
		m_isFinished = true;
	}
}

