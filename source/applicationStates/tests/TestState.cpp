/*
 * =====================================================================================
 *
 *       Filename:  TestState.cpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 20:06:13
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "AudioTestState.hpp"
#include "DisplayTestState.hpp"
#include "GamePad.hpp"
#include "GamePadTestState.hpp"
#include "OpenGLTestState.hpp"
#include "TestState.hpp"

void TestState::update() {
	if(GamePad::isKeyPressedOnce(GameKey::A))      ApplicationStateStack::getInstance().push<OpenGLTestState>();
	if(GamePad::isKeyPressedOnce(GameKey::B))      ApplicationStateStack::getInstance().push<DisplayTestState>();
	if(GamePad::isKeyPressedOnce(GameKey::Left))   ApplicationStateStack::getInstance().push<GamePadTestState>();
	if(GamePad::isKeyPressedOnce(GameKey::Right))  ApplicationStateStack::getInstance().push<AudioTestState>();
	if(GamePad::isKeyPressedOnce(GameKey::Select)) ApplicationStateStack::getInstance().pop();
}

void TestState::draw() {
	m_font.drawString(4, 0,   "A:      OpenGL");
	m_font.drawString(4, 16,  "B:      Display");
	m_font.drawString(4, 32,  "Left:   GamePad");
	m_font.drawString(4, 48,  "Right:  Audio");
	//m_font.drawString(4, 64,  "Up:     ");
	//m_font.drawString(4, 80,  "Down:   ");
	//m_font.drawString(4, 96,  "Start:  ");
	m_font.drawString(4, 112, "Select: Exit");
}

