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

Dialog::Dialog() {
	m_position = Position::Top;
	
	m_rectangle.resize(144, 40);
	
	m_nbLines = 0;
	
	m_currentLine = 0;
	
	m_dialogArrow.load("graphics/interface/dialogArrow.png", 7, 6);
	m_dialogArrow.addAnimation({0, 1}, 250);
}

Dialog::~Dialog() {
}

void Dialog::draw(u8 lineOffset) {
	if(m_currentLine != lineOffset) {
		m_font.resetTimer();
	}
	
	m_currentLine = lineOffset;
	
	if(m_position == Position::Top) {
		m_rectangle.setPosition(8, 24);
	} else {
		m_rectangle.setPosition(8, 96);
	}
	
	m_rectangle.draw();
	
	m_nbLines = m_font.drawTextBox(m_rectangle.x() + 8, m_rectangle.y() + 0, m_rectangle.width() - 16, m_rectangle.height(), U"L'[0]Arbre Bojo[/] est tout à l'est de cette grotte.", lineOffset);
	
	if(m_currentLine + 2 < m_nbLines) {
		m_dialogArrow.playAnimation(m_rectangle.x() + m_rectangle.width() - 8, m_rectangle.y() + m_rectangle.height() - 7, 0);
	}
	
	m_font.drawString(0, 100, U"truc", Color::white);
}

