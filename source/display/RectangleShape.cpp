/*
 * =====================================================================================
 *
 *       Filename:  RectangleShape.cpp
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
#include "RectangleShape.hpp"
#include "Shader.hpp"

RectangleShape::RectangleShape(float x, float y, u16 width, u16 height) {
	move(x, y);
	resize(width, height);
}

void RectangleShape::draw(Color color, bool wireframe) {
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
	
	
	if(wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	
	if(wireframe) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	Shader::currentShader->disableVertexAttribArray("color");
	Shader::currentShader->disableVertexAttribArray("coord2d");
}

