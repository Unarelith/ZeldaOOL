/*
 * =====================================================================================
 *
 *       Filename:  MenuState.cpp
 *
 *    Description:
 *
 *        Created:  02/10/2014 14:30:35
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "GamePad.hpp"
#include "MenuState.hpp"

void MenuState::update() {
	m_menu.update();

	if(GamePad::isKeyPressedOnce(GameKey::Start)) {
		AudioPlayer::playEffect("menuClose");

		m_stateStack->pop();
	}
}

void MenuState::draw() {
	m_statsBar.draw();

	m_menu.draw();
}

