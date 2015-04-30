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

void TransitionState::update() {
	m_transition->update();
	
	if(m_transition->atEnd()) {
		m_stateStack->pop();
	}
}

void TransitionState::draw() {
	m_transition->draw();
}

