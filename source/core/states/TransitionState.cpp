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
#include "ApplicationStateStack.hpp"
#include "Debug.hpp"
#include "TransitionState.hpp"

void TransitionState::update() {
	if(!m_transition || m_transition->atEnd()) {
		if(!m_transition) DEBUG("Empty TransitionState created, I'll pop it");

		ApplicationStateStack::getInstance().pop();
	} else {
		m_transition->update();
	}
}

void TransitionState::draw(RenderTarget &target, RenderStates states) const {
	if (m_transition)
		target.draw(*m_transition, states);

	if(m_transition->drawStatsBar()) {
		target.draw(m_statsBar, states);
	}
}

