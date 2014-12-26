/*
 * =====================================================================================
 *
 *       Filename:  View.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/2014 14:17:30
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

#include "View.hpp"

View::View() {
}

View::View(float x, float y, u16 width, u16 height) {
	load(x, y, width, height);
}

View::~View() {
}

void View::load(float x, float y, u16 width, u16 height) {
	reset(x, y, width, height);
	
	m_shader.loadFromFile("shaders/view.v.glsl", "shaders/view.f.glsl");
	
	Shader::bind(&m_shader);
	
	glm::mat4 projectionMatrix = glm::ortho(0.0f, (float)m_width + m_x, (float)m_height + m_y, 0.0f);
	
	m_shader.setUniform("u_projectionMatrix", projectionMatrix);
	m_shader.setUniform("u_viewPosition", m_x + m_posX, m_y + m_posY);
	
	Shader::bind(nullptr);
}

void View::enable() {
	Shader::bind(&m_shader);
}

void View::disable() {
	Shader::bind(nullptr);
}

void View::reset(float x, float y, u16 width, u16 height) {
	m_x = x;
	m_y = y;
	
	m_posX = 0;
	m_posY = 0;
	
	m_width = width;
	m_height = height;
}

void View::updateUniform() {
	Shader::bind(&m_shader);
	
	m_shader.setUniform("u_viewPosition", m_x + m_posX, m_y + m_posY);
	
	Shader::bind(nullptr);
}

void View::move(float offsetX, float offsetY) {
	m_posX += offsetX;
	m_posY += offsetY;
	
	updateUniform();
}

void View::setPosition(float x, float y) {
	m_posX = x;
	m_posY = y;
	
	updateUniform();
}

