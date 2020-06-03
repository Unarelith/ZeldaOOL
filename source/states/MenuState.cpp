/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
// #include <gk/audio/AudioPlayer.hpp> // FIXME: GAMEKIT
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "GameKey.hpp"
#include "MenuState.hpp"

void MenuState::update() {
	m_statsBar.update();

	m_menu.update();

	if(gk::GamePad::isKeyPressedOnce(GameKey::Start)) {
		// gk::AudioPlayer::playSound("sfx-menuClose"); // FIXME: GAMEKIT

		m_stateStack->pop();
	}
}

void MenuState::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	target.draw(m_statsBar, states);

	target.draw(m_menu, states);
}

