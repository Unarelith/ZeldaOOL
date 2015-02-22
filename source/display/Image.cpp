/*
 * =====================================================================================
 *
 *       Filename:  Image.cpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:24:39
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "Image.hpp"
#include "ResourceHandler.hpp"
#include "Shader.hpp"

Image::Image(const std::string &resourceName) {
	load(resourceName);
}

void Image::load(const std::string &resourceName) {
	m_texture = &ResourceHandler::getInstance().get<Texture>(resourceName);
	
	m_width = m_texture->width();
	m_height = m_texture->height();
	
	m_posRect = FloatRect(0, 0, m_width, m_height);
	m_clipRect = FloatRect(0, 0, m_width, m_height);
}

void Image::setClipRect(float x, float y, u16 width, u16 height) {
	m_clipRect.reset(x, y, width, height);
}

void Image::setPosRect(float x, float y, u16 width, u16 height) {
	m_posRect.reset(x, y, width, height);
}

void Image::draw(float x, float y, s16 width, s16 height) {
	if(width == -1) width = m_width;
	if(height == -1) height = m_height;
	
	setPosRect(x, y, width, height);
	
	draw();
}

void Image::draw() {
	GLfloat vertices[] = {
		m_posRect.x,					m_posRect.y,
		m_posRect.x + m_posRect.width,	m_posRect.y,
		m_posRect.x + m_posRect.width,	m_posRect.y + m_posRect.height,
		m_posRect.x,					m_posRect.y + m_posRect.height
	};
	
	FloatRect texRect = FloatRect(
		m_clipRect.x / float(m_width),
		m_clipRect.y / float(m_height),
		m_clipRect.width / float(m_width),
		m_clipRect.height / float(m_height)
	);
	
	GLfloat texCoords[] = {
		texRect.x,					texRect.y,
		texRect.x + texRect.width,	texRect.y,
		texRect.x + texRect.width,	texRect.y + texRect.height,
		texRect.x,					texRect.y + texRect.height
	};
	
	std::vector<float> colors = m_color.makeArray(4);
	
	static const GLubyte indices[] = {
		0, 1, 3,
		3, 1, 2
	};
	
	Shader::currentShader->enableVertexAttribArray("coord2d");
	Shader::currentShader->enableVertexAttribArray("texCoord");
	Shader::currentShader->enableVertexAttribArray("color");
	
	glVertexAttribPointer(Shader::currentShader->attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(Shader::currentShader->attrib("texCoord"), 2, GL_FLOAT, GL_FALSE, 0, texCoords);
	glVertexAttribPointer(Shader::currentShader->attrib("color"), 4, GL_FLOAT, GL_FALSE, 0, colors.data());
	
	Texture::bind(m_texture);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	
	Texture::bind(nullptr);
	
	Shader::currentShader->disableVertexAttribArray("texCoord");
	Shader::currentShader->disableVertexAttribArray("coord2d");
}

