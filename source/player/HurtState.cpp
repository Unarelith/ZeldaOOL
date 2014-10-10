/*
 * =====================================================================================
 *
 *       Filename:  HurtState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/2014 22:59:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "HurtState.hpp"
#include "ShaderManager.hpp"

HurtState::HurtState() {
	m_state = State::MoveBack;
	
	m_timer.start();
}

HurtState::~HurtState() {
}

void HurtState::update() {
	if(m_state == State::MoveBack) {
		if(m_movementCounter < 32) {
			m_player.mapCollisions();
			
			m_player.move(m_player.vx() * 0.4, m_player.vy() * 0.4);
			
			m_movementCounter += 0.4;
		} else {
			m_state = State::CanMove;
		}
	} else {
		MovingState::move();
		
		if(m_timer.time() > 3000) {
			m_player.setNextStateType(StateType::TypeStanding);
		}
	}
}

void HurtState::draw() {
	if(m_timer.time() % 300 < 150) {
		glUniform1i(ShaderManager::currentShader().uniform("u_paletteID"), 1);
	}
	
	if(m_state == State::MoveBack || (m_player.vx() == 0 && m_player.vy() == 0)) {
		m_player.drawFrame(m_player.x(), m_player.y(), m_player.direction());
	} else {
		m_player.playAnimation(m_player.x(), m_player.y(), m_player.direction());
	}
	
	glUniform1i(ShaderManager::currentShader().uniform("u_paletteID"), 0);
}

