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
#include "MessageBoxState.hpp"

void MessageBoxState::update() {
	m_messageBox.update();
}

void MessageBoxState::draw() {
	m_parent->draw();
	
	m_messageBox.draw();
}

