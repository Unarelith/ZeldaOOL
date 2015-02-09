/*
 * =====================================================================================
 *
 *       Filename:  Font.cpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 03:06:32
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
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
	Shader::currentShader->enableVertexAttribArray("color");
	
	GLfloat colors[] = {
		color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f,
		color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f,
		color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f,
		color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f
	};
	
	glVertexAttribPointer(Shader::currentShader->attrib("color"), 4, GL_FLOAT, GL_FALSE, 0, colors);
	
	if(c > 128 && c < 195) {
		m_sprite.drawFrame(x, y, c + 35);
	}
	else if(c >= 32) {
		m_sprite.drawFrame(x, y, c - 29);
	}
	
	Shader::currentShader->disableVertexAttribArray("color");
}

void Font::drawString(float x, float y, const std::string &str, Color color) {
	for(auto &it : str) {
		drawChar(x, y, it, color);
		x += charWidth();
	}
}

