/*
 * =====================================================================================
 *
 *       Filename:  DialogState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/09/2014 19:38:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "DialogState.hpp"
#include "GameStateManager.hpp"
#include "Keyboard.hpp"
#include "Sound.hpp"

DialogState::DialogState(GameState *parent) : GameState(parent) {
	m_currentLine = 0;
}

DialogState::~DialogState() {
}

void DialogState::update() {
	if(Keyboard::isKeyPressed(Keyboard::B)) {
		GameStateManager::pop();
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::A)) {
		if(m_currentLine + 2 < m_dialog.nbLines()) {
			Sound::Effect::dialogContinue.play();
			
			m_currentLine++;
		} else {
			GameStateManager::pop();
		}
	}
}

void DialogState::render() {
	m_parent->render();
	
	m_dialog.draw(m_currentLine);
}

