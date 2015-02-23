/*
 * =====================================================================================
 *
 *       Filename:  MessageBoxTestState.cpp
 *
 *    Description:  
 *
 *        Created:  22/02/2015 18:00:30
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "MessageBoxState.hpp"
#include "MessageBoxTestState.hpp"
#include "OpenGL.hpp"

MessageBoxTestState::MessageBoxTestState() {
	glClearColor(0.3f, 0.5f, 1.0f, 1.0f);
}

MessageBoxTestState::~MessageBoxTestState() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void MessageBoxTestState::update() {
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		std::string text("L'[1]Arbre Bojo[0] est tout à l'est de cette grotte.");
		
		ApplicationStateStack::getInstance().push<MessageBoxState>(text, this);
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::B)) {
		std::string text("Vous obtenez [2]30 Rubis[0]!\nC'est bien.");
		
		ApplicationStateStack::getInstance().push<MessageBoxState>(text, this, MessageBox::Position::Bottom);
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void MessageBoxTestState::draw() {
	m_font.drawString(4, 4, "A: MessageBox 1");
	
	m_font.drawString(4, 76, "B: MessageBox 2");
}

