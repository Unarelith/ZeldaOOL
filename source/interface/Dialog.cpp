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
}

Dialog::~Dialog() {
}

void Dialog::draw() {
	if(m_position == Position::Top) {
		m_rectangle.setPosition(8, 24);
	} else {
		m_rectangle.setPosition(8, 96);
	}
	
	m_rectangle.draw();
	
	m_font.drawTextBox(m_rectangle.x() + 8, m_rectangle.y() + 0, m_rectangle.width() - 16, m_rectangle.height(), U"L'Arbre Bojo est tout à l'est de cette grotte.");
}

