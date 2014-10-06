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
#define GLM_FORCE_RADIANS
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Application.hpp"
#include "Config.hpp"
#include "Font.hpp"
#include "Sound.hpp"

Font::Font() {
}

Font::Font(std::string filename, u16 charWidth, u16 charHeight) {
	load(filename, charWidth, charHeight);
}

Font::~Font() {
}

void Font::load(std::string filename, u16 charWidth, u16 charHeight) {
	Sprite::load(filename, charWidth, charHeight);
	
	m_shader.load("shaders/font.v.glsl", "shaders/font.f.glsl");
	ShaderManager::push(m_shader);
	
	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, 0.0f);
	
	glUniformMatrix4fv(m_shader.uniform("u_projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	
	ShaderManager::pop();
}

void Font::drawChar(float x, float y, u8 c) {
	if(c > 128 && c < 195) {
		drawFrame(x, y, c + 35);
	}
	else if(c >= 32) {
		drawFrame(x, y, c - 29);
	}
}

void Font::drawString(float x, float y, std::string str, s16 charsToDraw) {
	ShaderManager::push(m_shader);
	
	ShaderManager::currentShader().enableVertexAttribArray("color");
	
	setColor(Color::text);
	
	u16 tmpX = 0;
	for(u16 i = 0 ; i < str.length() ; i++) {
		if(tmpX > charsToDraw) break;
		
		if(str[i] == '[' && str[i + 1] >= '0' && str[i + 1] <= '9' && str[i + 2] == ']') {
			switch(str[i + 1] - '0') {
				case 1:		setColor(Color::blue);		break;
				case 2:		setColor(Color::red);		break;
				default:	setColor(Color::text);		break;
			}
			
			i += 3;
		}
		
		drawChar(x + (tmpX++ * charWidth()), y, str[i]);
	}
	
	ShaderManager::currentShader().disableVertexAttribArray("color");
	
	ShaderManager::pop();
}

void Font::setColor(Color color) {
	m_colors[0] = m_colors[3] = m_colors[6] = m_colors[9] = color.r;
	m_colors[1] = m_colors[4] = m_colors[7] = m_colors[10] = color.g;
	m_colors[2] = m_colors[5] = m_colors[8] = m_colors[11] = color.b;
	
	glVertexAttribPointer(ShaderManager::currentShader().attrib("color"), 3, GL_FLOAT, GL_FALSE, 0, m_colors);
}

