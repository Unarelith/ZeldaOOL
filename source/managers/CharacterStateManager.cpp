/*
 * =====================================================================================
 *
 *       Filename:  CharacterStateManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/10/2014 16:45:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "CharacterStateManager.hpp"
#include "HurtState.hpp"
#include "MovingState.hpp"
#include "PushingState.hpp"
#include "StandingState.hpp"
#include "SwordState.hpp"

CharacterStateManager::CharacterStateManager() {
	m_state = new StandingState;
	
	m_nextState = m_state->name();
}

CharacterStateManager::~CharacterStateManager() {
}

void CharacterStateManager::update() {
	m_state->update();
}

void CharacterStateManager::updateStates() {
	if(m_nextState != m_state->name()) {
		delete m_state;
		
		if(m_nextState == "Hurt") {
			m_state = new HurtState;
		}
		else if(m_nextState == "Moving") {
			m_state = new MovingState;
		}
		else if(m_nextState == "Pushing") {
			m_state = new PushingState;
		}
		else if(m_nextState == "Standing") {
			m_state = new StandingState;
		}
		else if(m_nextState == "Sword") {
			m_state = new SwordState;
		}
	}
}

void CharacterStateManager::draw() {
	m_state->draw();
}

