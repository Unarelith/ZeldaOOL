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
}

CharacterStateManager::CharacterStateManager(Character *character) {
	load(character);
}

CharacterStateManager::~CharacterStateManager() {
	if(m_currentState) delete m_currentState;
}

void CharacterStateManager::load(Character *character) {
	m_stateTransition = character->defaultState();
	m_currentState = m_stateTransition();
	
	m_stateTransition = nullFunction();
}

void CharacterStateManager::update() {
	m_currentState->update();
}

void CharacterStateManager::updateStates() {
	m_nextState = m_stateTransition();
	
	if(m_nextState) {
		delete m_currentState;
		m_currentState = m_nextState;
		resetNextState();
	}
}

void CharacterStateManager::render() {
	m_currentState->render();
}

void CharacterStateManager::setNextState(ICharacterState::StateTransition stateTransition) {
	m_stateTransition = stateTransition;
}

void CharacterStateManager::resetNextState() {
	m_nextState = nullptr;
	m_stateTransition = nullFunction();
}

