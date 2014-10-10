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
	m_movementCounter = 0;
	
	m_player.hurt();
}

HurtState::~HurtState() {
}

void HurtState::update() {
	if(m_movementCounter < 16) {
		m_player.mapCollisions();
		
		m_player.move(m_player.vx() * 0.4, m_player.vy() * 0.4);
		
		m_movementCounter += 0.4;
	} else {
		m_player.setNextStateType(PlayerState::StateType::TypeStanding);
	}
}

void HurtState::draw() {
	m_player.drawFrame(m_player.x(), m_player.y(), m_player.direction());
}

