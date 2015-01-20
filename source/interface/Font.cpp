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

Font::Font(const std::string &filename, u16 charWidth, u16 charHeight) {
	load(filename, charWidth, charHeight);
}

void Font::load(const std::string &filename, u16 charWidth, u16 charHeight) {
	Sprite::load(filename, charWidth, charHeight);
}

void Font::drawChar(float x, float y, u8 c) {
	if(c > 128 && c < 195) {
		drawFrame(x, y, c + 35);
	}
	else if(c >= 32) {
		drawFrame(x, y, c - 29);
	}
}

void Font::drawString(float x, float y, const std::string &str, s16 charsToDraw) {
	setColorMod(Color::text);
	
	u16 tmpX = 0;
	for(u16 i = 0 ; i < str.length() ; i++) {
		if(tmpX > charsToDraw) break;
		
		if(str[i] == '[' && str[i + 1] >= '0' && str[i + 1] <= '9' && str[i + 2] == ']') {
			switch(str[i + 1] - '0') {
				case 1:		setColorMod(Color::blue);		break;
				case 2:		setColorMod(Color::red);		break;
				default:	setColorMod(Color::text);		break;
			}
			
			i += 3;
		}
		
		drawChar(x + (tmpX++ * charWidth()), y, str[i]);
	}
}

