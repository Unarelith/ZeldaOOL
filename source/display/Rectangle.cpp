/*
 * =====================================================================================
 *
 *       Filename:  Rectangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/09/2014 17:06:57
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
#include "Rectangle.hpp"

Rectangle::Rectangle() {
	loadShader();
}

Rectangle::Rectangle(float x, float y, u16 width, u16 height) {
	move(x, y);
	resize(width, height);
	
	loadShader();
}

Rectangle::~Rectangle() {
}

void Rectangle::loadShader() {
	m_shader.load("shaders/rectangle.v.glsl", "shaders/rectangle.f.glsl");
	ShaderManager::push(m_shader);
	
	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT, 0.0f);
	
	glUniformMatrix4fv(ShaderManager::currentShader().uniform("u_projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	
	ShaderManager::pop();
}

void Rectangle::draw() {
	GLfloat vertices[] = {
		m_x,			m_y,
		m_x + m_width,	m_y,
		m_x + m_width,	m_y + m_height,
		m_x,			m_y + m_height
	};
	
	GLfloat colors[] = {
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f
	};
	
	GLubyte indices[] = {
		0, 1, 3,
		3, 1, 2
	};
	
	ShaderManager::push(m_shader);
	
	ShaderManager::currentShader().enableVertexAttribArray("coord2d");
	ShaderManager::currentShader().enableVertexAttribArray("color");
	
	glVertexAttribPointer(ShaderManager::currentShader().attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(ShaderManager::currentShader().attrib("color"), 3, GL_FLOAT, GL_FALSE, 0, colors);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	
	ShaderManager::currentShader().disableVertexAttribArray("color");
	ShaderManager::currentShader().disableVertexAttribArray("coord2d");
	
	ShaderManager::pop();
}

