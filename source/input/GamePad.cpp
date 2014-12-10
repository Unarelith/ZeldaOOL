/*
 * =====================================================================================
 *
 *       Filename:  GamePad.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 19:22:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GamePad.hpp"
#include "KeyboardHandler.hpp"

GamePad::GamePad() {
	m_inputHandler = std::unique_ptr<InputHandler>(new KeyboardHandler);
	
	m_keysPressed[Key::Left] = false;
	m_keysPressed[Key::Right] = false;
	m_keysPressed[Key::Up] = false;
	m_keysPressed[Key::Down] = false;
	
	m_keysPressed[Key::A] = false;
	m_keysPressed[Key::B] = false;
	
	m_keysPressed[Key::Start] = false;
	m_keysPressed[Key::Select] = false;
}

GamePad::~GamePad() {
}

void GamePad::update() {
	m_inputHandler->update();
}

bool GamePad::isKeyPressed(Key key) {
	return m_inputHandler->isKeyPressed(key);
}

bool GamePad::isKeyPressedOnce(Key key) {
	if(GamePad::isKeyPressed(key)) {
		if(!m_keysPressed[key]) {
			m_keysPressed[key] = true;
			return true;
		} else {
			return false;
		}
	} else {
		m_keysPressed[key] = false;
		return false;
	}
}

