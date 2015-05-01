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
#include "Player.hpp"

MessageBoxState::MessageBoxState(const std::string &text, ApplicationState *parent, MessageBox::Position position)
	: ApplicationState(parent), m_messageBox(text, position)
{
	if(Player::player.y() + 32 < MessageBox::Position::Bottom) {
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

