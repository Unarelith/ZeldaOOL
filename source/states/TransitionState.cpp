/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2014 17:42:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "TransitionState.hpp"

TransitionState::TransitionState(Transition *transition) {
	m_transition = transition;
}

TransitionState::~TransitionState() {
	delete m_transition;
}

void TransitionState::update() {
	m_transition->update();
	
	if(m_transition->atEnd()) {
		GameStateManager::pop();
	}
}

void TransitionState::render() {
	m_transition->draw();
}

