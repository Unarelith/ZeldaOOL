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

void Font::drawChar(float x, float y, char c) {
	if(c >= 32) {
		drawFrame(x, y, c - 29);
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
	
	//glVertexAttribPointer(m_shader.attrib("color"), 3, GL_FLOAT, GL_FALSE, 0, colors);
	glUniform3f(m_shader.uniform("u_color"), color.r, color.g, color.b);
	
	for(u16 i = 0 ; i < str.length() ; i++) {
		drawChar(x + (i * m_frameWidth), y, str[i]);
	}
	
	Application::window.useDefaultShader();
}

