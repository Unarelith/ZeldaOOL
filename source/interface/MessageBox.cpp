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
#include <SFML/Graphics/RenderTarget.hpp>

#include <gk/core/input/GamePad.hpp>
#include <gk/resource/AudioPlayer.hpp>

#include "GameKey.hpp"
#include "MessageBox.hpp"

MessageBox::MessageBox(const std::string &text, Position position) : m_textBox(text, 144, 40) {
	sf::Transformable::setPosition(8, position);

	m_dialogArrow.setPosition(m_rectangle.getSize().x - 8, m_rectangle.getSize().y - 7);

	m_rectangle.setSize({144, 40});
	m_rectangle.setFillColor(sf::Color::Black);
}

void MessageBox::update() {
	if(gk::GamePad::isKeyPressedOnce(GameKey::A)
	|| gk::GamePad::isKeyPressedOnce(GameKey::B)) {
		if(m_textBox.textDisplayFinished()) {
			gk::AudioPlayer::playSound("sfx-dialogContinue");

			m_finished = m_textBox.scrollDown();
		} else {
			m_textBox.stopTextAnimation();
		}
	}

	m_textBox.updateTextSprites();
}

void MessageBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();

	target.draw(m_rectangle, states);

	target.draw(m_textBox, states);

	if(m_textBox.textDisplayFinished() && !m_textBox.isAtLastPage()
	&& m_textBox.charTimerTime() % 540 > 269) {
		target.draw(m_dialogArrow, states);
	}
}

