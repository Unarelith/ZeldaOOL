/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.cpp
 *
 *    Description:  
 *
 *        Created:  05/10/2014 17:42:59
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "TransitionState.hpp"

void TransitionState::update() {
	m_transition->update();
	
	if(m_transition->atEnd()) {
		m_stateStack->pop();
	}
}

void TransitionState::draw() {
	m_transition->draw();
}

