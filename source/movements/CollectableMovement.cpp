/*
 * =====================================================================================
 *
 *       Filename:  CollectableMovement.cpp
 *
 *    Description:  
 *
 *        Created:  26/02/2015 19:14:02
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "CollectableMovement.hpp"
#include "MovementComponent.hpp"

void CollectableMovement::process(SceneObject &object) {
	auto *movementComponent = object.getComponent<MovementComponent>();
	
	if(m_type == Type::Dropped) {
		if(m_movementCounter < 5) {
			m_movementCounter += 0.25f;
			
			movementComponent->vy = 0.25f;
		} else {
			m_isFinished = true;
		}
	}
	else if(m_type == Type::OutOfChest) {
		if(m_movementCounter < 8) {
			m_movementCounter += 0.125f;
			
			movementComponent->vy = -0.125f;
		} else {
			m_isFinished = true;
		}
	}
}

