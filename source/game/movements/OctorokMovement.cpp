/*
 * =====================================================================================
 *
 *       Filename:  OctorokMovement.cpp
 *
 *    Description:
 *
 *        Created:  18/01/2015 20:12:12
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <cstdlib>

#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/MovementComponent.hpp>

#include "OctorokMovement.hpp"
#include "PositionComponent.hpp"

void OctorokMovement::reset(gk::SceneObject &) {
	m_state = State::Standing;

	m_timer.reset();

	m_movementCounter = 0;

	m_randomMinTimeToWait = 1000 + (rand() % 2) * 500;
	m_randomMaxMovement = 16 + (rand() % 5) * 8;
}

void OctorokMovement::process(gk::SceneObject &object) {
	auto &movementComponent = object.get<gk::MovementComponent>();
	auto &positionComponent = object.get<PositionComponent>();

	movementComponent.speed = 0.3f;

	if(m_state == State::Standing) {
		m_timer.start();

		if(m_timer.time() > m_randomMinTimeToWait) {
			int r = rand() % 3 - 1;
			m_v.x = r;
			m_v.y = r;

			if(m_v.x != 0 && m_v.y != 0) {
				if(rand() % 2 == 0) {
					m_v.x = 0;
				} else {
					m_v.y = 0;
				}
			}

			movementComponent.v = m_v;

			if(object.has<gk::CollisionComponent>()) {
				object.get<gk::CollisionComponent>().checkCollisions(object);
			}

			positionComponent.updateDirection(m_v);

			if(!movementComponent.isBlocked.x || !movementComponent.isBlocked.y) {
				m_state = State::Moving;
			}
		}
	}
	else if(m_state == State::Moving) {
		if(movementComponent.isBlocked.x || movementComponent.isBlocked.y) {
			if(m_v.x != 0) {
				m_v.y = m_v.x;
				m_v.x = 0;
			}
			else if(m_v.y != 0) {
				m_v.x = m_v.y;
				m_v.y = 0;
			}
		}

		if(m_movementCounter < m_randomMaxMovement) {
			movementComponent.v = m_v;

			positionComponent.updateDirection(m_v);

			m_movementCounter += 0.3f;
		} else {
			reset(object);
		}
	}

	m_isFinished = true;
}

