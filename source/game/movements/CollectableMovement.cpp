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

