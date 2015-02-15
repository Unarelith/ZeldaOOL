/*
 * =====================================================================================
 *
 *       Filename:  OctorokMovement.cpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 01:01:27
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "MovementComponent.hpp"
#include "OctorokMovement.hpp"
#include "PositionComponent.hpp"

void OctorokMovement::reset(SceneObject &) {
	m_state = State::Standing;
	
	m_timer.reset();
	
	m_movementCounter = 0;
	
	m_randomMinTimeToWait = 1000 + (rand() % 2) * 500;
	m_randomMaxMovement = 16 + (rand() % 5) * 8;
	
	//movable.stopAnimation(movable.direction());
}

void OctorokMovement::process(SceneObject &object) {
	MovementComponent *movementComponent = object.getComponent<MovementComponent>();
	PositionComponent *positionComponent = object.getComponent<PositionComponent>();
	
	movementComponent->speed = 0.3f;
	
	if(m_state == State::Standing) {
		m_timer.start();
		
		if(m_timer.time() > m_randomMinTimeToWait) {
			m_vx = rand() % 3 - 1;
			m_vy = rand() % 3 - 1;
			
			if(m_vx != 0 && m_vy != 0) {
				if(rand() % 2 == 0) {
					m_vx = 0;
				} else {
					m_vy = 0;
				}
			}
			
			movementComponent->vx = m_vx;
			movementComponent->vy = m_vy;
			
			for(auto &it : movementComponent->collisionHandlers) {
				it(object);
			}
			
			positionComponent->updateDirection(m_vx, m_vy);
			
			if(!movementComponent->isBlocked) {
				m_state = State::Moving;
			}
		}
	}
	else if(m_state == State::Moving) {
		if(movementComponent->isBlocked) {
			if(m_vx != 0) {
				m_vy = m_vx;
				m_vx = 0;
			}
			else if(m_vy != 0) {
				m_vx = m_vy;
				m_vy = 0;
			}
		}
		
		if(m_movementCounter < m_randomMaxMovement) {
			movementComponent->vx = m_vx;
			movementComponent->vy = m_vy;
			
			positionComponent->updateDirection(m_vx, m_vy);
			
			m_movementCounter += 0.3f;
		} else {
			reset(object);
		}
	}
}

