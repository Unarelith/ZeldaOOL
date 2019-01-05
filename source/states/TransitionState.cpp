/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.cpp
 *
 *    Description:
 *
 *        Created:  05/10/2014 17:42:59
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/core/Debug.hpp>

#include "TransitionState.hpp"

TransitionState::TransitionState(gk::ApplicationState *parent) : gk::ApplicationState(parent) {
	m_statsBar.update();
}

void TransitionState::update() {
	m_statsBar.update();

	if(!m_transition || m_transition->atEnd()) {
		if(!m_transition) DEBUG("Empty TransitionState created, I'll pop it");

		m_stateStack->pop();
	} else {
		m_transition->update();
	}
}

void TransitionState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	if (m_transition)
		target.draw(*m_transition, states);

	if(m_transition->drawStatsBar()) {
		target.draw(m_statsBar, states);
	}
}

