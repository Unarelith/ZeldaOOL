/*
 * =====================================================================================
 *
 *       Filename:  CollectableMovement.cpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:41:51
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include <cmath>

#include "CollectableMovement.hpp"
#include "MovementComponent.hpp"

void CollectableMovement::process(SceneObject &object) {
	auto &movementComponent = object.get<MovementComponent>();
	
	if(m_type == Type::Dropped) {
		if(m_movementCounter < 24) {
			if(m_movementCounter > 4 && m_speed == -m_baseSpeed) {
				m_speed = -m_baseSpeed / 2;
			}
			if(m_movementCounter > 6 && m_speed == -m_baseSpeed / 2) {
				m_speed = -m_baseSpeed / 3;
			}
			if(m_movementCounter > 8 && m_speed == -m_baseSpeed / 3) {
				m_speed = m_baseSpeed / 2;
			}
			if(m_movementCounter > 16 && m_speed == m_baseSpeed / 2) {
				m_speed = -m_baseSpeed / 2;
			}
			if(m_movementCounter > 20 && m_speed == -m_baseSpeed / 2) {
				m_speed = m_baseSpeed / 2;
			}
			
			m_movementCounter += fabs(m_speed);
			
			movementComponent.vy = m_speed;
		} else {
			m_isFinished = true;
		}
	}
	else if(m_type == Type::OutOfChest) {
		if(m_movementCounter < 8) {
			m_movementCounter += 0.125f;
			
			movementComponent.vy = -0.125f;
		} else {
			m_isFinished = true;
		}
	}
}

