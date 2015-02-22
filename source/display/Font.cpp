/*
 * =====================================================================================
 *
 *       Filename:  Font.cpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 03:06:32
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Font.hpp"
#include "Shader.hpp"

Font::Font(const std::string &filename, u16 charWidth, u16 charHeight) {
	load(filename, charWidth, charHeight);
}

void Font::load(const std::string &filename, u16 charWidth, u16 charHeight) {
	m_sprite.load(filename, charWidth, charHeight);
}

void Font::drawChar(float x, float y, u8 c, Color color) {
	m_sprite.setColor(color);
	
	if(c > 128 && c < 195) {
		m_sprite.drawFrame(x, y, c + 35);
	}
	else if(c >= 32) {
		m_sprite.drawFrame(x, y, c - 29);
	}
}

void Font::drawString(float x, float y, const std::string &str, Color color) {
	for(auto &it : str) {
		drawChar(x, y, it, color);
		x += charWidth();
	}
}

