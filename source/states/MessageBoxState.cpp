/*
 * =====================================================================================
 *
 *       Filename:  MessageBoxState.cpp
 *
 *    Description:
 *
 *        Created:  23/02/2015 16:53:33
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/ApplicationStateStack.hpp>

#include "MessageBoxState.hpp"
#include "PositionComponent.hpp"
#include "World.hpp"

MessageBoxState::MessageBoxState(const std::string &text, gk::ApplicationState *parent) : gk::ApplicationState(parent), m_messageBox(text) {
	if(World::getInstance().player().get<PositionComponent>().y + 32 < MessageBox::Position::Bottom) {
		m_messageBox.setPosition(8, MessageBox::Position::Bottom);
	}
}

void MessageBoxState::update() {
	m_messageBox.update();

	if(m_messageBox.finished()) {
		m_stateStack->pop();
	}
}

void MessageBoxState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.draw(*m_parent, states);

	target.draw(m_messageBox, states);
}

