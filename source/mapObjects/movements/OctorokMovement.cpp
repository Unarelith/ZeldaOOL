/*
 * =====================================================================================
 *
 *       Filename:  OctorokMovement.cpp
 *
 *    Description:  
 *
 *        Created:  18/01/2015 20:12:12
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Movable.hpp"
#include "Octorok.hpp"
#include "OctorokMovement.hpp"

void OctorokMovement::reset(Movable &movable) {
	m_state = State::Standing;
	
	m_timer.reset();
	
	m_movementCounter = 0;
	
	m_randomMinTimeToWait = 1000 + (rand() % 2) * 500;
	m_randomMaxMovement = 16 + (rand() % 5) * 8;
	
	movable.getAnimation(movable.direction()).stop();
}

void OctorokMovement::process(Movable &movable) {
	Octorok &octorok = static_cast<Octorok&>(movable);
	octorok.setSpeed(0.3f);
	
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
			
			octorok.setVelocity(m_vx, m_vy);
			
			octorok.testCollisions();
			octorok.updateDirection();
			
			if(!octorok.blocked()) {
				m_state = State::Moving;
			}
		}
	}
	else if(m_state == State::Moving) {
		if(octorok.blocked()) {
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
			octorok.setVelocity(m_vx, m_vy);
			octorok.updateDirection();
			
			m_movementCounter += 0.3f;
		} else {
			reset(octorok);
		}
	}
}

