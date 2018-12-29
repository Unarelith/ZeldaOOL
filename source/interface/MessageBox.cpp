/*
 * =====================================================================================
 *
 *       Filename:  MessageBox.cpp
 *
 *    Description:
 *
 *        Created:  22/02/2015 17:50:03
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "GamePad.hpp"
#include "MessageBox.hpp"

MessageBox::MessageBox(const std::string &text, Position position) : m_textBox(text, 144, 40) {
	gk::Transformable::setPosition(8, position);

	m_dialogArrow.setPosition(m_rectangle.width() - 8, m_rectangle.height() - 7);
}

void MessageBox::update() {
	if(GamePad::isKeyPressedOnce(GameKey::A)
	|| GamePad::isKeyPressedOnce(GameKey::B)) {
		if(m_textBox.textDisplayFinished()) {
			AudioPlayer::playEffect("dialogContinue");

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

