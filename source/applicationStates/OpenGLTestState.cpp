/*
 * =====================================================================================
 *
 *       Filename:  OpenGLTestState.cpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 23:01:17
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "OpenGLTestState.hpp"

#include "Shader.hpp"

void OpenGLTestState::draw() {
	GLfloat vertices[] = {
		0,  0,
		64, 0,
		64, 6 * 16,
		0,  6 * 16
	};
	
	GLfloat texCoords[] = {
		0, 0,
		1, 0,
		1, 1,
		0, 1
	};
	
	GLubyte indices[] = {
		0, 1, 3,
		3, 1, 2
	};
	
	Shader::currentShader->enableVertexAttribArray("coord2d");
	Shader::currentShader->enableVertexAttribArray("texCoord");
	
	glVertexAttribPointer(Shader::currentShader->attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(Shader::currentShader->attrib("texCoord"), 2, GL_FLOAT, GL_FALSE, 0, texCoords);
	
	Texture::bind(&m_texture);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	
	Texture::bind(nullptr);
	
	Shader::currentShader->disableVertexAttribArray("texCoord");
	Shader::currentShader->disableVertexAttribArray("coord2d");
}

