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
}

GamePad::~GamePad() {
}

void GamePad::update() {
	m_inputHandler->update();
}

bool GamePad::isKeyPressed(Key key) {
	return m_inputHandler->isKeyPressed(key);
}

