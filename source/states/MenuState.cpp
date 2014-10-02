/*
 * =====================================================================================
 *
 *       Filename:  MenuState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/10/2014 14:30:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GameStateManager.hpp"
#include "Keyboard.hpp"
#include "MenuState.hpp"
#include "Sound.hpp"

MenuState::MenuState() {
	
}

MenuState::~MenuState() {
}

void MenuState::update() {
	m_menu.update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::Start)) {
		Sound::Effect::menuClose.play();
		
		GameStateManager::pop();
	}
}

void MenuState::render() {
	m_statsBar.draw();
	
	m_menu.draw();
}

