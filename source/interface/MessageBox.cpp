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

MessageBox::MessageBox() {
	m_charTimer.start();
}

void MessageBox::update() {
	if(GamePad::isKeyPressedOnce(GameKey::A)
	&& m_charTimer.time() / 42 > m_text.length()) {
		AudioPlayer::playEffect("dialogContinue");
		m_page++;
	}
}

void MessageBox::draw() {
	m_rectangle.draw();
	
	drawText();
	
	if(m_charTimer.time() / 42 > m_text.length()) {
		m_dialogArrow.draw(m_rectangle.x() + m_rectangle.width() - 8, m_rectangle.y() + m_rectangle.height() - 7);
	}
}

void MessageBox::drawText() {
	u16 x = m_rectangle.x() + 8;
	u16 y = m_rectangle.y();
	
	for(u16 i = 0 ; i < m_text.length() ; i++) {
		if(y + m_font.charHeight() > m_rectangle.y() + m_rectangle.height()) break;
		
		if(m_charTimer.time() / 42 < i) {
			AudioPlayer::playEffect("textLetter");
			break;
		}
		
		// Fix problems with UTF-8 characters
		//if((u8)m_text[i] == 195) continue;
		
		if(m_text[i] == '\n') {
			x = m_rectangle.x() + 8;
			y += m_font.charHeight();
			
			continue;
		}
		
		if(m_text[i] == ' ') {
			if(x == m_rectangle.x() + 8) continue;
			
			size_t nextSpace = m_text.find_first_of(' ', i + 1);
			
			u8 wordLength = nextSpace - i - 1;
			
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

