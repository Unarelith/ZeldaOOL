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
#include "ApplicationStateStack.hpp"
#include "AudioPlayer.hpp"
#include "GamePad.hpp"
#include "MessageBox.hpp"

MessageBox::MessageBox() {
	m_charTimer.start();
}

void MessageBox::update() {
	if(GamePad::isKeyPressedOnce(GameKey::A)
	&& m_charTimer.time() / 42 > m_charPerLine * (2u + m_page)) {
		AudioPlayer::playEffect("dialogContinue");
		
		m_charTimer.setTime(m_charPerLine * (2 + m_page) * 42);
		
		if(m_text.length() / m_charPerLine > m_page + 1u) {
			m_page++;
		} else {
			ApplicationStateStack::getInstance().pop();
			return; // This object don't exist anymore
		}
	}
	
	m_displayArrow = (m_charTimer.time() % 540 > 269)
	              && (m_text.length() / m_charPerLine > m_page + 1u);
}

void MessageBox::draw() {
	m_rectangle.draw();
	
	drawText();
	
	if(m_charTimer.time() / 42 > m_charPerLine * (2u + m_page)) {
		if(m_displayArrow) m_dialogArrow.draw(m_rectangle.x() + m_rectangle.width() - 8, m_rectangle.y() + m_rectangle.height() - 7);
	}
}

void MessageBox::drawText() {
	u16 x = m_rectangle.x() + 8;
	u16 y = m_rectangle.y();
	
	for(u16 i = m_page * m_charPerLine ; i < m_text.length() ; i++) {
		if(y + m_font.charHeight() > m_rectangle.y() + m_rectangle.height()) break;
		
		if(m_charTimer.time() / 42 < i) {
			AudioPlayer::playDelayedEffect("textLetter", 40);
			break;
		}
		
		if(m_text[i] == '\n') {
			x = m_rectangle.x() + 8;
			y += m_font.charHeight();
			
			continue;
		}
		
		if(m_text[i] == ' ') {
			if(x == m_rectangle.x() + 8) continue;
			
			size_t nextSpace = m_text.find_first_of(' ', i + 1);
			
			u8 wordLength = ((nextSpace != std::string::npos) ? nextSpace : m_text.length()) - i - 1;
			
			//if(wordLength + (x - m_rectangle.x() - 8) / m_font.charWidth() > m_charPerLine) {
			if(x + wordLength * m_font.charWidth() > m_rectangle.x() + m_rectangle.width() - 16) {
				x = m_rectangle.x() + 8;
				y += m_font.charHeight();
				
				continue;
			}
		}
		
		m_font.drawChar(x, y, m_text[i], Color::text);
		
		x += m_font.charWidth();
	}
}

