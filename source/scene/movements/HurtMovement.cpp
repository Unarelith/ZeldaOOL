/*
 * =====================================================================================
 *
 *       Filename:  HurtMovement.cpp
 *
 *    Description:  
 *
 *        Created:  18/01/2015 18:56:01
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "HurtMovement.hpp"
#include "MovementComponent.hpp"

void HurtMovement::process(SceneObject &object) {
	auto &movement = object.get<MovementComponent>();
	
	m_oldSpeed = movement.speed;
	movement.speed = m_speed;
	
	if(m_movementCounter < 16) {
		movement.vx = m_vx;
		movement.vy = m_vy;
		
		m_movementCounter += m_speed;
	} else {
		movement.speed = m_oldSpeed;
	}
}

