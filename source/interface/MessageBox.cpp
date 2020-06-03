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

#include "GameKey.hpp"
#include "MessageBox.hpp"

MessageBox::MessageBox(const std::string &text, Position position) : m_textBox(text, 144, 40) {
	gk::Transformable::setPosition(8, position);

	m_dialogArrow.setPosition(m_rectangle.width() - 8, m_rectangle.height() - 7);
}

void MessageBox::update() {
	if(gk::GamePad::isKeyPressedOnce(GameKey::A)
	|| gk::GamePad::isKeyPressedOnce(GameKey::B)) {
		if(m_textBox.textDisplayFinished()) {
			// gk::AudioPlayer::playSound("sfx-dialogContinue"); // FIXME: GAMEKIT

			m_finished = m_textBox.scrollDown();
		} else {
			m_textBox.stopTextAnimation();
		}
	}

	m_textBox.updateTextSprites();
}

void MessageBox::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	states.transform *= getTransform();

	target.draw(m_rectangle, states);

	target.draw(m_textBox, states);

	if(m_textBox.textDisplayFinished() && !m_textBox.isAtLastPage()
	&& m_textBox.charTimerTime() % 540 > 269) {
		target.draw(m_dialogArrow, states);
	}
}

