/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2014 01:08:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "TransitionState.hpp"

TransitionState::TransitionState(Transition *transition) {
	m_transition = std::unique_ptr<Transition>(transition);
}

TransitionState::~TransitionState() {
}

void TransitionState::update() {
	m_transition->update();
	
	if(m_transition->atEnd()) {
		ApplicationStateStack::getInstance().pop();
	}
}

void TransitionState::draw() {
	m_transition->draw();
}

