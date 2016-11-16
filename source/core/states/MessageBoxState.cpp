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
	if(Scene::player && Scene::player->get<PositionComponent>().y + 32 < MessageBox::Position::Bottom) {
		m_messageBox.setPosition(MessageBox::Position::Bottom);
	}
}

void MessageBoxState::update() {
	m_messageBox.update();

	if(m_messageBox.finished()) {
		ApplicationStateStack::getInstance().pop();
	}
}

void MessageBoxState::draw() {
	m_parent->draw();

	m_messageBox.draw();
}

