/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 19:51:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "KeyboardHandler.hpp"

KeyboardHandler::KeyboardHandler() {
	m_keys[GamePad::Left] = sf::Keyboard::Left;
	m_keys[GamePad::Right] = sf::Keyboard::Right;
	m_keys[GamePad::Up] = sf::Keyboard::Up;
	m_keys[GamePad::Down] = sf::Keyboard::Down;
	
	m_keys[GamePad::A] = sf::Keyboard::X;
	m_keys[GamePad::B] = sf::Keyboard::W;
	
	m_keys[GamePad::Start] = sf::Keyboard::Return;
	m_keys[GamePad::Select] = sf::Keyboard::BackSpace;
}

KeyboardHandler::~KeyboardHandler() {
}

void KeyboardHandler::update() {
}

bool KeyboardHandler::isKeyPressed(GamePad::Key key) {
	return sf::Keyboard::isKeyPressed(m_keys[key]);
}

