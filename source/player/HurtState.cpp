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
#include "StandingState.hpp"

HurtState::HurtState() {
	m_player.hurt();
	
	m_movement = new HurtMovement(&m_player);
}

HurtState::~HurtState() {
	delete m_movement;
}

void HurtState::update() {
	m_movement->update();
	
	if(m_movement->isFinished()) {
		m_player.stateManager().setNextState(new StandingState);
	}
}

void HurtState::draw() {
	m_player.drawFrame(m_player.x(), m_player.y(), m_player.direction());
}

