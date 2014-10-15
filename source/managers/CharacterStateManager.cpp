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

CharacterStateManager::CharacterStateManager() {
	m_state = nullptr;
	m_nextState = nullptr;
}

CharacterStateManager::~CharacterStateManager() {
}

void CharacterStateManager::update() {
	if(m_state) m_state->update();
}

void CharacterStateManager::updateStates() {
	if(m_nextState) {
		if(m_state) delete m_state;
		m_state = m_nextState;
		m_nextState = nullptr;
	}
}

void CharacterStateManager::draw() {
	if(m_state) m_state->draw();
}

