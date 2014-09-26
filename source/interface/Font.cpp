/*
 * =====================================================================================
 *
 *       Filename:  Font.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/09/2014 20:41:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Font.hpp"

Font::Font() : Sprite("graphics/interface/font.png", 8, 16) {
}

Font::~Font() {
}

void Font::drawChar(s16 x, s16 y, char c) {
	if(c >= 32) {
		drawFrame(x, y, c - 29);
	}
}

void Font::drawString(s16 x, s16 y, std::string str) {
	for(u16 i = 0 ; i < str.length() ; i++) {
		drawChar(x + (i * m_frameWidth), y, str[i]);
	}
}

