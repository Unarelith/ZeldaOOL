/*
 * =====================================================================================
 *
 *       Filename:  MenuState.cpp
 *
 *    Description:
 *
 *        Created:  02/10/2014 14:30:35
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/resource/AudioPlayer.hpp>

#include "GameKey.hpp"
#include "MenuState.hpp"

void MenuState::update() {
	m_statsBar.update();

	m_menu.update();

	if(gk::GamePad::isKeyPressedOnce(GameKey::Start)) {
		gk::AudioPlayer::playSound("sfx-menuClose");

		m_stateStack->pop();
	}
}

void MenuState::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(m_statsBar, states);

	target.draw(m_menu, states);
}

