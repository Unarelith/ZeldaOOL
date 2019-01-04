/*
 * =====================================================================================
 *
 *       Filename:  CollectableMovement.cpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 23:41:51
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <cmath>

#include <gk/scene/component/MovementComponent.hpp>

#include "CollectableMovement.hpp"

void CollectableMovement::process(gk::SceneObject &object) {
	auto &movementComponent = object.get<gk::MovementComponent>();

	if(m_type == Type::Dropped) {
		if(m_movementCounter < 24) {
			if(m_movementCounter > 4 && m_movementCounter <= 6) {
				m_speed = -m_baseSpeed / 2;
			}
			else if(m_movementCounter <= 8) {
				m_speed = -m_baseSpeed / 3;
			}
			else if(m_movementCounter <= 16) {
				m_speed = m_baseSpeed / 2;
			}
			else if(m_movementCounter <= 20) {
				m_speed = -m_baseSpeed / 2;
			}
			else if(m_movementCounter > 20) {
				m_speed = m_baseSpeed / 2;
			}

			m_movementCounter += fabs(m_speed);

			movementComponent.v.y = m_speed;
		} else {
			m_isFinished = true;
		}
	}
	else if(m_type == Type::Chest) {
		if(m_movementCounter < 8) {
			m_movementCounter += 0.125f;

			movementComponent.v.y = -0.125f;
		} else {
			m_isFinished = true;
		}
	}
}

