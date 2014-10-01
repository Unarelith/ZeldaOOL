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

Font::Font() : Sprite("graphics/interface/font.png", 8, 16) {
	m_shader.load("shaders/font.v.glsl", "shaders/font.f.glsl");
	m_shader.useProgram();
	
	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, 0.0f);
	
	glUniformMatrix4fv(m_shader.uniform("u_projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	
	Application::window.useDefaultShader();
}

Font::~Font() {
}

void Font::drawChar(float x, float y, char c) {
		drawFrame(x, y, c - 29);
}

void Font::drawChar32(float x, float y, char32_t c) {
	if((s16)c >= 32) {
		drawFrame(x, y, c - 29);
	}
	else if((s16)c < 0) {
		drawFrame(x, y, 227 + c);
	}
}

void Font::drawString(float x, float y, std::string str, Color color) {
	m_shader.useProgram();
	
	GLfloat colors[] = {
		color.r, color.g, color.b,
		color.r, color.g, color.b,
		color.r, color.g, color.b,
		color.r, color.g, color.b
	};
	
	glEnableVertexAttribArray(m_shader.attrib("color"));
	
	glVertexAttribPointer(m_shader.attrib("color"), 3, GL_FLOAT, GL_FALSE, 0, colors);
	
	for(u16 i = 0 ; i < str.length() ; i++) {
		drawChar(x + (i * m_frameWidth), y, str[i]);
	}
	
	glDisableVertexAttribArray(m_shader.attrib("color"));
	
	Application::window.useDefaultShader();
}

u8 Font::drawTextBox(float x, float y, u16 width, u16 height, std::u32string str, u16 lineOffset, Color color) {
	m_shader.useProgram();
	
	glEnableVertexAttribArray(m_shader.attrib("color"));
	
	u16 i = 0;
	float tmpY = y;
	std::u32string line = str;
	u32 lineWidth = 0;
	u32 charsDrawn = 0;
	u32 maxChars = 0;
	
	size_t nextSpace = line.find_first_of(' ');
	size_t nextTag = line.find_first_of('[');
	
	lineWidth += line.find_first_of(' ') * charWidth();
	
	if(nextTag < nextSpace) {
		lineWidth -= 3 * charWidth();
	}
	
	maxChars += lineWidth / charWidth();
	
	m_timer.start();
	
	m_soundTimer.start();
	
	while(i < line.length()) {
		char c = line[i];
		
		if(line[i] == ' ') {
			nextSpace = line.find_first_of(' ', i + 1);
			nextTag = line.find_first_of('[', i + 1);
			
			if(nextSpace != std::string::npos) {
				lineWidth += line.substr(i + 1, nextSpace - i).length() * charWidth();
				
				if((tmpY - y) / charHeight() == 1 || lineOffset == 0) {
					maxChars += line.substr(i + 1, nextSpace - i).length();
				}
			} else {
				lineWidth += line.length() * charWidth();
				
				if(tmpY - y / charHeight() == 1 || lineOffset == 0) {
					maxChars += line.length();
				}
			}
			
			if(nextTag < nextSpace) {
				lineWidth -= 3 * charWidth();
		
				if(tmpY - y / charHeight() == 1 || lineOffset == 0) {
					maxChars -= 3;
				}
			}
			
			if(lineWidth > width) {
				line = line.substr(i + 1);
				i = 0;
				tmpY += charHeight();
				lineWidth = 0;
				
				continue;
			}
		}
		else if(line[i] == '[' && line[i + 1] >= '0' && line[i + 1] <= '9' && line[i + 2] == ']') {
			switch(line[i + 1] - '0') {
				default: color = Color::blue;
			}
			
			line.erase(i, 3);
			continue;
		}
		else if(line[i] == '[' && line[i + 1] == '/' && line[i + 2] == ']') {
			color = Color::text;
			
			line.erase(i, 3);
			continue;
		}
		
		if(tmpY - lineOffset * charHeight() >= y && tmpY - y + charHeight() < height + lineOffset * charWidth() * 2) {
			GLfloat colors[] = {
				color.r, color.g, color.b,
				color.r, color.g, color.b,
				color.r, color.g, color.b,
				color.r, color.g, color.b
			};
			
			glVertexAttribPointer(m_shader.attrib("color"), 3, GL_FLOAT, GL_FALSE, 0, colors);
			
			if(charsDrawn < m_timer.time() / 48) {
				if(m_timer.time() / 48 < maxChars) {
					if(m_soundTimer.time() > 48) {
						Sound::Effect::textLetter.play();
						
						m_soundTimer.reset();
						m_soundTimer.start();
					}
				}
				
				drawChar32(x + i * charWidth(), tmpY - lineOffset * charHeight(), c);
				
				charsDrawn++;
			}
		}
		
		i++;
	}
	
	glDisableVertexAttribArray(m_shader.attrib("color"));
	
	Application::window.useDefaultShader();
	
	return tmpY / charHeight();
}

