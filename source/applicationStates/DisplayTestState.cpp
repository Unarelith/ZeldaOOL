/*
 * =====================================================================================
 *
 *       Filename:  DisplayTestState.cpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:16:09
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "DisplayTestState.hpp"
#include "GamePad.hpp"

DisplayTestState::DisplayTestState() {
	m_sprite.addAnimation({4, 0}, 150);
}

void DisplayTestState::update() {
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void DisplayTestState::draw() {
	m_image.draw();
	
	m_sprite.drawFrame(64, 0, 0);
	m_sprite.playAnimation(80, 0, 0);
	
	m_rect.draw(Color::red);
	
	m_font.drawString(64, 16, "Haha lol", Color::blue);
}

