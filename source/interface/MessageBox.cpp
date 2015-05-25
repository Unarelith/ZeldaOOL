/*
 * =====================================================================================
 *
 *       Filename:  MessageBox.cpp
 *
 *    Description:  
 *
 *        Created:  22/02/2015 17:50:03
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "GamePad.hpp"
#include "MessageBox.hpp"

MessageBox::MessageBox(const std::string &text, Position position) : m_textBox(text) {
	setPosition(position);
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
}

void MessageBox::draw() {
	m_rectangle.draw();
	
	m_textBox.draw(m_rectangle.x(), m_rectangle.y(), m_rectangle.width(), m_rectangle.height());
	
	if(m_textBox.textDisplayFinished() && !m_textBox.isAtLastPage()
	&& m_textBox.charTimerTime() % 540 > 269) {
		m_dialogArrow.draw(m_rectangle.x() + m_rectangle.width()  - 8,
		                   m_rectangle.y() + m_rectangle.height() - 7);
	}
}

