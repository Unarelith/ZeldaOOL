/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 10:43:39
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "Debug.hpp"
#include "TransitionState.hpp"

void TransitionState::update() {
	if(m_transition) m_transition->update();
	
	if(!m_transition || m_transition->atEnd()) {
		if(!m_transition) DEBUG("Empty TransitionState created, I'll pop it.");
		
		ApplicationStateStack::getInstance().pop();
	}
}

void TransitionState::draw() {
	if(m_transition) m_transition->draw();
}

