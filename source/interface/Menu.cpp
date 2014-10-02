/*
 * =====================================================================================
 *
 *       Filename:  Menu.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/10/2014 14:33:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "Menu.hpp"

Menu::Menu() {
	m_background.load("graphics/interface/menuBackground.png");
	
	m_cursor.load("graphics/interface/menuCursor.png");
	m_cursorX = 0;
	m_cursorY = 0;
}

Menu::~Menu() {
}

void Menu::update() {
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Left, 250)) {
		m_cursorX--;
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Right, 250)) {
		m_cursorX++;
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Up, 250)) {
		m_cursorY--;
	}
	
	if(Keyboard::isKeyPressedWithDelay(Keyboard::Down, 250)) {
		m_cursorY++;
	}
	
	if(m_cursorX < 0) {
		m_cursorX = 3;
		m_cursorY--;
	}
	
	if(m_cursorY < 0) {
		m_cursorY = 3;
	}
	
	if(m_cursorX > 3) {
		m_cursorX = 0;
		m_cursorY++;
	}
	
	if(m_cursorY > 3) {
		m_cursorY = 0;
	}
}

void Menu::draw() {
	m_background.draw(0, 16);
	
	m_cursor.draw(22 + m_cursorX * 32, 25 + m_cursorY * 24);
}

