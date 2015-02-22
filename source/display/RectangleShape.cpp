/*
 * =====================================================================================
 *
 *       Filename:  RectangleShape.cpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:52:18
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

void RectangleShape::draw(Color color) {
	GLfloat vertices[] = {
		m_x,			m_y,
		m_x + m_width,	m_y,
		m_x + m_width,	m_y + m_height,
		m_x,			m_y + m_height
	};
	
	std::vector<float> colors = color.makeArray(4);
	
	static const GLubyte indices[] = {
		0, 1, 3,
		3, 1, 2
	};
	
	Shader::currentShader->enableVertexAttribArray("coord2d");
	Shader::currentShader->enableVertexAttribArray("color");
	
	glVertexAttribPointer(Shader::currentShader->attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(Shader::currentShader->attrib("color"), 4, GL_FLOAT, GL_FALSE, 0, colors.data());
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	
	Shader::currentShader->disableVertexAttribArray("color");
	Shader::currentShader->disableVertexAttribArray("coord2d");
}

