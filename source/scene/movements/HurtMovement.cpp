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
	
	if(m_movementCounter < 16) {
		movement.v = {m_vx, m_vy};
		
		m_movementCounter += movement.speed;
	} else {
		m_isFinished = true;
	}
}

