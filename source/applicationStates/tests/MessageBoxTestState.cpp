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
	//m_messageBox.setText("L'[1]Arbre Bojo[0] est tout à l'est de cette grotte.");
	m_messageBox.setText("Vous obtenez [2]30 Rubis[0]!\nC'est bien.");
	
	glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
}

MessageBoxTestState::~MessageBoxTestState() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void MessageBoxTestState::update() {
	m_messageBox.update();
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void MessageBoxTestState::draw() {
	m_messageBox.draw();
}

