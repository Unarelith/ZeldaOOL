/*
 * =====================================================================================
 *
 *       Filename:  GamePadTestState.cpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 17:48:04
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "GamePadTestState.hpp"

void GamePadTestState::update() {
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void GamePadTestState::draw() {
	m_font.drawString(4, 0, "A:");
	m_font.drawString(4, 16, "B:");
	m_font.drawString(4, 32, "Left:");
	m_font.drawString(4, 48, "Right:");
	m_font.drawString(4, 64, "Up:");
	m_font.drawString(4, 80, "Down:");
	m_font.drawString(4, 96, "Start:");
	
	m_font.drawString(100, 0,   std::to_string(GamePad::isKeyPressed(GameKey::A)));
	m_font.drawString(100, 16,  std::to_string(GamePad::isKeyPressed(GameKey::B)));
	m_font.drawString(100, 32,  std::to_string(GamePad::isKeyPressed(GameKey::Left)));
	m_font.drawString(100, 48,  std::to_string(GamePad::isKeyPressed(GameKey::Right)));
	m_font.drawString(100, 64,  std::to_string(GamePad::isKeyPressed(GameKey::Up)));
	m_font.drawString(100, 80,  std::to_string(GamePad::isKeyPressed(GameKey::Down)));
	m_font.drawString(100, 96,  std::to_string(GamePad::isKeyPressed(GameKey::Start)));
	
	m_font.drawString(116, 0,   std::to_string(GamePad::isKeyPressedOnce(GameKey::A)));
	m_font.drawString(116, 16,  std::to_string(GamePad::isKeyPressedOnce(GameKey::B)));
	m_font.drawString(116, 32,  std::to_string(GamePad::isKeyPressedOnce(GameKey::Left)));
	m_font.drawString(116, 48,  std::to_string(GamePad::isKeyPressedOnce(GameKey::Right)));
	m_font.drawString(116, 64,  std::to_string(GamePad::isKeyPressedOnce(GameKey::Up)));
	m_font.drawString(116, 80,  std::to_string(GamePad::isKeyPressedOnce(GameKey::Down)));
	m_font.drawString(116, 96,  std::to_string(GamePad::isKeyPressedOnce(GameKey::Start)));
}
