/*
 * =====================================================================================
 *
 *       Filename:  CharacterStateManager.cpp
 *
 *    Description:  
 *
 *        Created:  13/10/2014 16:45:40
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "CharacterStateManager.hpp"
#include "HurtState.hpp"
#include "MovingState.hpp"
#include "PushingState.hpp"
#include "StandingState.hpp"
#include "SwordState.hpp"

void CharacterStateManager::update() {
	if(m_currentState) m_currentState->update();
}

void CharacterStateManager::updateStates() {
	if(m_stateTransition) {
		m_currentState.reset(m_stateTransition());
		m_stateTransition = nullptr;
	}
}

void CharacterStateManager::render() {
	if(m_currentState) m_currentState->render();
}

