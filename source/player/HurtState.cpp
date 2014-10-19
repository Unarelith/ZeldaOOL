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

HurtState::HurtState(Battler *battler) : BattlerState(battler) {
	m_name = "Hurt";
	
	m_battler->hurt();
	
	m_movement = new HurtMovement(m_battler);
}

HurtState::~HurtState() {
	delete m_movement;
}

void HurtState::update() {
	m_movement->update();
	
	if(m_movement->isFinished()) {
		m_battler->stateManager().setNextState(m_battler->defaultState());
	}
}

void HurtState::draw() {
	m_battler->drawFrame(m_battler->x(), m_battler->y(), m_battler->direction());
}

