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
#include "MapManager.hpp"
#include "Sound.hpp"

DialogState::DialogState(GameState *parent) : GameState(parent) {
	Sprite::pause = true;
}

DialogState::~DialogState() {
}

void DialogState::update() {
	MapManager::currentMap->update();
	
	m_dialog.update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::B)
	|| Keyboard::isKeyPressedOnce(Keyboard::A)) {
		if(!m_dialog.lastPage()) {
			Sound::Effect::dialogContinue.play();
			
			m_dialog.scrollDown();
		} else {
			Sprite::pause = false;
			
			GameStateManager::pop();
		}
	}
}

void DialogState::render() {
	m_parent->render();
	
	m_dialog.draw();
}

