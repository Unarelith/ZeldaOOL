/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 10:43:39
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "TransitionState.hpp"

void TransitionState::update() {
	m_transition->update();
	
	if(m_transition->atEnd()) {
		ApplicationStateStack::getInstance().pop();
	}
}

void TransitionState::draw() {
	m_parent->draw();
	
	m_transition->draw();
}

