/*
 * =====================================================================================
 *
 *       Filename:  DialogState.cpp
 *
 *    Description:  
 *
 *        Created:  29/09/2014 19:38:51
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "DialogState.hpp"
#include "GamePad.hpp"
#include "Map.hpp"
#include "Player.hpp"

DialogState::DialogState(ApplicationState *parent, const std::string &text) : ApplicationState(parent) {
	Sprite::pause = true;
	
	if(Player::player.y() + 32 < 96) {
		m_dialog.setPosition(Dialog::Position::Bottom);
	}
	
	m_dialog.setText(text);
}

void DialogState::update() {
	Map::currentMap->update();
	
	m_dialog.update();
	
	if(GamePad::isKeyPressedOnce(GameKey::B)
	|| GamePad::isKeyPressedOnce(GameKey::A)) {
		if(!m_dialog.lastPage()) {
			AudioPlayer::playEffect("dialogContinue");
			
			m_dialog.scrollDown();
		} else {
			Sprite::pause = false;
			
			m_stateStack->pop();
		}
	}
}

void DialogState::draw() {
	m_parent->draw();
	
	m_dialog.draw();
}

