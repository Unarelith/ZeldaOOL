/*
 * =====================================================================================
 *
 *       Filename:  MessageBoxState.cpp
 *
 *    Description:
 *
 *        Created:  23/02/2015 16:53:33
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "MessageBoxState.hpp"
#include "PositionComponent.hpp"
#include "Scene.hpp"

MessageBoxState::MessageBoxState(const std::string &text, ApplicationState *parent) : ApplicationState(parent), m_messageBox(text) {
	// FIXME: Map rework
	// if(Scene::player && Scene::player->get<PositionComponent>().y + 32 < MessageBox::Position::Bottom) {
	// 	m_messageBox.setPosition(8, MessageBox::Position::Bottom);
	// }
}

void MessageBoxState::update() {
	m_messageBox.update();

	if(m_messageBox.finished()) {
		ApplicationStateStack::getInstance().pop();
	}
}

void MessageBoxState::draw(RenderTarget &target, RenderStates states) const {
	target.draw(*m_parent, states);

	target.draw(m_messageBox, states);
}

