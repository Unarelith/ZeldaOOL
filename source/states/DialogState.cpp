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
#include "AudioPlayer.hpp"
#include "CharacterManager.hpp"
#include "DialogState.hpp"
#include "GameStateManager.hpp"
#include "Keyboard.hpp"
#include "Map.hpp"

DialogState::DialogState(GameState *parent, std::string text) : GameState(parent) {
	Sprite::pause = true;
	
	if(CharacterManager::player.y() + 32 < 96) {
		m_dialog.setPosition(Dialog::Position::Bottom);
	}
	
	m_dialog.setText(text);
}

DialogState::~DialogState() {
}

void DialogState::update() {
	Map::currentMap->update(true);
	
	m_dialog.update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::B)
	|| Keyboard::isKeyPressedOnce(Keyboard::A)) {
		if(!m_dialog.lastPage()) {
			AudioPlayer::playEffect("dialogContinue");
			
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

