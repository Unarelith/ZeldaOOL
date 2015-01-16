/*
 * =====================================================================================
 *
 *       Filename:  Dialog.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/09/2014 20:34:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Dialog.hpp"
#include "SoundEffect.hpp"

Dialog::Dialog() {
	m_rectangle.setPosition(8, Position::Top);
	m_rectangle.resize(144, 40);
	
	m_font.load("interface-font", 8, 16);
	
	m_dialogArrow.load("interface-dialogArrow");
	m_arrowTimer.start();
	
	m_currentLine = 0;
	
	m_charTimer.start();
	m_soundTimer.start();
}

Dialog::~Dialog() {
}

void Dialog::update() {
	if(m_soundTimer.time() > 60
	&& !waitForUser()) {
		SoundEffect::play("textLetter");
		
		m_soundTimer.reset();
		m_soundTimer.start();
	}
	
	if(m_arrowTimer.time() > 500) {
		m_arrowTimer.reset();
		m_arrowTimer.start();
	}
}

void Dialog::draw() {
	m_rectangle.draw();
	
	drawText();
	
	if(!lastPage() && waitForUser() && m_arrowTimer.time() < 250) {
		m_dialogArrow.draw(m_rectangle.x() + m_rectangle.width() - 8, m_rectangle.y() + m_rectangle.height() - 7);
	}
}

void Dialog::drawText() {
	m_font.drawString(m_rectangle.x() + 8, m_rectangle.y(), m_lines[m_currentLine].second, m_charTimer.time() / 42);
	m_font.drawString(m_rectangle.x() + 8, m_rectangle.y() + m_font.charHeight(), m_lines[m_currentLine + 1].second, m_charTimer.time() / 42 - 16);
}

void Dialog::setText(std::string text) {
	s8 lineWidth = 0;
	u8 previousOffset = 0;
	
	size_t nextSpace = text.find_first_of(' ');
	size_t nextTag = text.find_first_of('[');
	
	lineWidth += nextSpace;
	
	while(nextTag != std::string::npos && nextTag < nextSpace) {
		lineWidth -= 3;
		
		nextTag = text.find_first_of('[', nextTag + 1);
	}
	
	for(u16 i = 0 ; i < text.length() ; i++) {
		if((u8)text[i] == 195) {
			text.erase(text.begin() + i);
			lineWidth--;
		}
		
		if(text[i] == '\n') {
			m_lines.push_back(std::make_pair(lineWidth, text.substr(previousOffset, i - previousOffset)));
			previousOffset = i + 1;
		}
		
		if(text[i] == ' ') {
			u8 wordLength = 0;
			
			nextSpace = text.find_first_of(' ', i + 1);
			nextTag = text.find_first_of('[', i + 1);
			
			if(nextSpace != std::string::npos) {
				nextSpace -= i;
				
				wordLength = text.substr(i, nextSpace).length();
			} else {
				wordLength = text.substr(i).length();
			}
			
			while(nextTag != std::string::npos && nextTag - i < nextSpace) {
				wordLength -= 3;
				
				nextTag = text.find_first_of('[', nextTag + 1);
			}
			
			if(nextSpace != std::string::npos) {
				if(lineWidth + wordLength > 16) {
					m_lines.push_back(std::make_pair(lineWidth, text.substr(previousOffset, i - previousOffset)));
					previousOffset = i + 1;
					lineWidth = wordLength;
				} else {
					lineWidth += wordLength;
				}
			} else {
				lineWidth += wordLength;
				
				m_lines.push_back(std::make_pair(lineWidth, text.substr(previousOffset)));
			}
		}
	}
}

void Dialog::scrollDown() {
	m_charTimer.setTime(36 * 16);
	
	m_currentLine++;
}

bool Dialog::waitForUser() {
	return (s32)m_charTimer.time() / 36 > m_lines[m_currentLine].first + m_lines[m_currentLine + 1].first + 2;
}

