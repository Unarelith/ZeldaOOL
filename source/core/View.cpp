/*
 * =====================================================================================
 *
 *       Filename:  View.cpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 23:35:04
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Shader.hpp"
#include "View.hpp"

View::View(float x, float y, u16 width, u16 height) {
	load(x, y, width, height);
}

void View::load(float x, float y, u16 width, u16 height) {
	reset(x, y, width, height);
}

void View::reset(float x, float y, u16 width, u16 height) {
	m_x = x;
	m_y = y;
	
	m_width = width;
	m_height = height;
}

void View::move(float offsetX, float offsetY) {
	m_x += offsetX;
	m_y += offsetY;
	
	Shader::currentShader->setUniform("u_viewPosition", m_x, m_y);
}

void View::setPosition(float x, float y) {
	m_x = x;
	m_y = y;
	
	Shader::currentShader->setUniform("u_viewPosition", m_x, m_y);
}

void View::bind(const View *view) {
	if(view) {
		Shader::currentShader->setUniform("u_viewPosition", view->m_x, view->m_y);
	} else {
		Shader::currentShader->setUniform("u_viewPosition", 0, 0);
	}
}

