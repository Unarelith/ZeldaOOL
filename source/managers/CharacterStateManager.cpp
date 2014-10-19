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

CharacterStateManager::CharacterStateManager(Character *character) {
	m_character = character;
	
	m_state = nullptr;
	
	m_nextState = m_character->defaultState();
	
	updateStates();
}

CharacterStateManager::~CharacterStateManager() {
}

void CharacterStateManager::update() {
	if(m_state) {
		m_state->update();
	}
}

void CharacterStateManager::updateStates() {
	if(!m_state || m_nextState != m_state->name()) {
		if(m_state) {
			delete m_state;
		}
		
		if(m_nextState == "Hurt") {
			m_state = new HurtState(static_cast<Battler*>(m_character));
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
		} else {
			m_state = nullptr;
		}
	}
}

void CharacterStateManager::draw() {
	if(m_state) {
		m_state->draw();
	}
}

