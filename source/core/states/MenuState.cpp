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
#include "ApplicationStateStack.hpp"
#include "AudioPlayer.hpp"
#include "GamePad.hpp"
#include "MenuState.hpp"

void MenuState::update() {
	m_statsBar.update();

	m_menu.update();

	if(GamePad::isKeyPressedOnce(GameKey::Start)) {
		AudioPlayer::playEffect("menuClose");

		m_stateStack->pop();
	}
}

void MenuState::draw(RenderTarget &target, RenderStates states) const {
	target.draw(m_statsBar, states);

	target.draw(m_menu, states);
}

