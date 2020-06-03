/*
 * =====================================================================================
 *
 *       Filename:  GameState.cpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 00:22:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
// #include <gk/audio/AudioPlayer.hpp> // FIXME: GAMEKIT
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "GameKey.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"

GameState::GameState() {
	World::setInstance(&m_world);

	// gk::AudioPlayer::playMusic("bgm-plain"); // FIXME: GAMEKIT
}

void GameState::update() {
	m_world.update();

	m_statsBar.update();

	if(gk::GamePad::isKeyPressedOnce(GameKey::Start)) {
		// gk::AudioPlayer::playSound("sfx-menuOpen"); // FIXME: GAMEKIT

		m_stateStack->push<MenuState>();
	}
}

void GameState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.draw(m_world, states);

	target.draw(m_statsBar, states);
}

