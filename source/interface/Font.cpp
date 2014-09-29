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

Font::Font() : Sprite("graphics/interface/font.png", 8, 16) {
	m_shader.load("shaders/font.v.glsl", "shaders/font.f.glsl");
	m_shader.useProgram();
	
	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, 0.0f);
	
	glUniformMatrix4fv(m_shader.uniform("u_projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	
	Application::window.useDefaultShader();
}

Font::~Font() {
}

void Font::drawChar(float x, float y, char32_t c) {
	if((s16)c >= 32) {
		drawFrame(x, y, c - 29);
	}
	else if((s16)c < 0) {
		drawFrame(x, y, 227 + c);
	}
}

void Font::drawString(float x, float y, std::u32string str, Color color) {
	m_shader.useProgram();
	
	glUniform3f(m_shader.uniform("u_color"), color.r, color.g, color.b);
	
	for(u16 i = 0 ; i < str.length() ; i++) {
		drawChar(x + (i * m_frameWidth), y, str[i]);
	}
	
	Application::window.useDefaultShader();
}

void Font::drawTextBox(float x, float y, u16 width, u16 height, std::u32string str, Color color) {
	m_shader.useProgram();
	
	glUniform3f(m_shader.uniform("u_color"), color.r, color.g, color.b);
	
	u16 i = 0;
	u16 tmpY = y;
	std::u32string line = str;
	u32 lineWidth = line.find_first_of(' ') * charWidth();
	while(i < line.length()) {
		char c = line[i];
		
		if(line[i] == ' ') {
			size_t nextSpace = line.find_first_of(' ', i + 1);
			
			if(nextSpace != std::string::npos) {
				lineWidth += line.substr(i + 1, nextSpace - i).length() * charWidth();
			} else {
				lineWidth += line.length() * charWidth();
			}
			
			if(lineWidth > width) {
				line = line.substr(i + 1);
				i = 0;
				tmpY += charHeight();
				lineWidth = 0;
				
				continue;
			}
		}
		
		drawChar(x + i * charWidth(), tmpY, c);
		i++;
	}
	
	Application::window.useDefaultShader();
}

