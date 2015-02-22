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
#include "MessageBoxTestState.hpp"
#include "OpenGL.hpp"

MessageBoxTestState::MessageBoxTestState() {
	m_messageBox.setText("L'Arbre Bojo est tout à l'est de cette grotte.");
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void MessageBoxTestState::update() {
	m_messageBox.update();
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
		
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	}
}

void MessageBoxTestState::draw() {
	m_messageBox.draw();
}

