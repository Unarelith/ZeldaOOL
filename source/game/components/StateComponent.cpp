/*
 * =====================================================================================
 *
 *       Filename:  StateComponent.cpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 17:43:38
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "StateComponent.hpp"

void StateComponent::update(gk::SceneObject &object) {
	if (m_state)
		m_state->update(object);
}

void StateComponent::setState(gk::SceneObject &object, StatePtr state) {
	if (m_state)
		m_state->onEnd(object);

	m_state = std::move(state);

	if (m_state)
		m_state->onBegin(object);
}

