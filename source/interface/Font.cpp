/*
 * =====================================================================================
 *
 *       Filename:  Font.cpp
 *
 *    Description:  
 *
 *        Created:  26/09/2014 20:41:45
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

void Font::drawChar(Vector2f position, u8 c, Color color) {
	m_sprite.setColorMod(color);
	
	if(c > 128 && c < 195) {
		m_sprite.drawFrame(position, c + 35);
	}
	else if(c >= 32) {
		m_sprite.drawFrame(position, c - 29);
	}
}

void Font::drawString(Vector2f position, const std::string &str, Color color) {
	for(auto &it : str) {
		drawChar(position, it, color);
		position.x += charWidth();
	}
}

