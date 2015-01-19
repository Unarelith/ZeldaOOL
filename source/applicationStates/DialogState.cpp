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
#include "Player.hpp"
#include "DialogState.hpp"
#include "Keyboard.hpp"
#include "Map.hpp"
#include "SoundEffect.hpp"

DialogState::DialogState(ApplicationState *parent, const std::string &text) : ApplicationState(parent) {
	Sprite::pause = true;
	
	if(Player::player.y() + 32 < 96) {
		m_dialog.setPosition(Dialog::Position::Bottom);
	}
	
	m_dialog.setText(text);
}

void DialogState::update() {
	Map::currentMap->update(true);
	
	m_dialog.update();
	
	if(Keyboard::isKeyPressedOnce(Keyboard::B)
	|| Keyboard::isKeyPressedOnce(Keyboard::A)) {
		if(!m_dialog.lastPage()) {
			SoundEffect::play("dialogContinue");
			
			m_dialog.scrollDown();
		} else {
			Sprite::pause = false;
			
			m_stateStack->pop();
		}
	}
}

void DialogState::render() {
	m_parent->render();
	
	m_dialog.draw();
}

