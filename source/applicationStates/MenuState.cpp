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
#include "Keyboard.hpp"
#include "MenuState.hpp"
#include "SoundEffect.hpp"

void MenuState::update() {
	m_menu.update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::Start)) {
		SoundEffect::play("menuClose");
		
		m_stateStack->pop();
	}
}

void MenuState::render() {
	m_statsBar.draw();
	
	m_menu.draw();
}

