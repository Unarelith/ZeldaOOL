/*
 * =====================================================================================
 *
 *       Filename:  TestState.cpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 20:06:13
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "AudioTestState.hpp"
#include "DisplayTestState.hpp"
#include "FactoriesTestState.hpp"
#include "GamePad.hpp"
#include "GamePadTestState.hpp"
#include "MapTestState.hpp"
#include "OpenGLTestState.hpp"
#include "SceneTestState.hpp"
#include "SceneObjectTestState.hpp"
#include "TestState.hpp"
#include "TransitionTestState.hpp"

void TestState::update() {
	if(m_page == 0) {
		if(GamePad::isKeyPressedOnce(GameKey::A))      ApplicationStateStack::getInstance().push<OpenGLTestState>();
		if(GamePad::isKeyPressedOnce(GameKey::B))      ApplicationStateStack::getInstance().push<DisplayTestState>();
		if(GamePad::isKeyPressedOnce(GameKey::Left))   ApplicationStateStack::getInstance().push<GamePadTestState>();
		if(GamePad::isKeyPressedOnce(GameKey::Right))  ApplicationStateStack::getInstance().push<AudioTestState>();
		if(GamePad::isKeyPressedOnce(GameKey::Up))     ApplicationStateStack::getInstance().push<MapTestState>();
		if(GamePad::isKeyPressedOnce(GameKey::Down))   ApplicationStateStack::getInstance().push<TransitionTestState>();
	}
	else if(m_page == 1) {
		if(GamePad::isKeyPressedOnce(GameKey::A))      ApplicationStateStack::getInstance().push<SceneObjectTestState>();
		if(GamePad::isKeyPressedOnce(GameKey::B))      ApplicationStateStack::getInstance().push<FactoriesTestState>();
		if(GamePad::isKeyPressedOnce(GameKey::Left))   ApplicationStateStack::getInstance().push<SceneTestState>();
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Start))  m_page++; m_page %= 2;
	if(GamePad::isKeyPressedOnce(GameKey::Select)) ApplicationStateStack::getInstance().pop();
}

void TestState::draw() {
	if(m_page == 0) {
		m_font.drawString(4, 0,   "A:      OpenGL");
		m_font.drawString(4, 16,  "B:      Display");
		m_font.drawString(4, 32,  "Left:   GamePad");
		m_font.drawString(4, 48,  "Right:  Audio");
		m_font.drawString(4, 64,  "Up:     Map");
		m_font.drawString(4, 80,  "Down:   Transitions");
	}
	else if(m_page == 1) {
		m_font.drawString(4, 0,   "A:      SceneObject");
		m_font.drawString(4, 16,  "B:      Factories");
		m_font.drawString(4, 32,  "Left:   Scene");
	}
	
	m_font.drawString(4, 104, "Start:  Next page");
	m_font.drawString(4, 120, "Select: Exit");
}

