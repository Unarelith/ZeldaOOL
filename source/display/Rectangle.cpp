/*
 * =====================================================================================
 *
 *       Filename:  Rectangle.cpp
 *
 *    Description:  
 *
 *        Created:  27/09/2014 17:06:57
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "OpenGL.hpp"
#include "Rectangle.hpp"
#include "Shader.hpp"

Rectangle::Rectangle(float x, float y, u16 width, u16 height) {
	move(x, y);
	resize(width, height);
}

void Rectangle::draw(Color color) {
	GLfloat vertices[] = {
		m_x,			m_y,
		m_x + m_width,	m_y,
		m_x + m_width,	m_y + m_height,
		m_x,			m_y + m_height
	};
	
	GLfloat colors[] = {
		color.r, color.g, color.b,
		color.r, color.g, color.b,
		color.r, color.g, color.b,
		color.r, color.g, color.b
	};
	
	GLubyte indices[] = {
		0, 1, 3,
		3, 1, 2
	};
	
	Shader::currentShader->enableVertexAttribArray("coord2d");
	Shader::currentShader->enableVertexAttribArray("color");
	
	glVertexAttribPointer(Shader::currentShader->attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(Shader::currentShader->attrib("color"), 3, GL_FLOAT, GL_FALSE, 0, colors);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	
	Shader::currentShader->disableVertexAttribArray("color");
	Shader::currentShader->disableVertexAttribArray("coord2d");
}

