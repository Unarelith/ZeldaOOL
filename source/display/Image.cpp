/*
 * =====================================================================================
 *
 *       Filename:  Image.cpp
 *
 *    Description:  
 *
 *        Created:  20/09/2014 16:22:12
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "Image.hpp"
#include "ResourceHandler.hpp"
#include "Shader.hpp"

Image::Image(const std::string &textureName) {
	load(textureName);
}

void Image::load(const std::string &textureName) {
	m_texture = &ResourceHandler::getInstance().get<Texture>(textureName);
	
	m_width = m_texture->width();
	m_height = m_texture->height();
	
	m_posRect = FloatRect(0, 0, m_width, m_height);
	m_clipRect = FloatRect(0, 0, m_width, m_height);
	
	m_colorMod = Color(255, 255, 255);
}

void Image::setClipRect(FloatRect rect) {
	m_clipRect.reset(rect);
}

void Image::setPosRect(FloatRect rect) {
	m_posRect.reset(rect);
}

void Image::draw(Vector2f position, s16 width, s16 height) {
	draw({position, (float)width, (float)height});
}

void Image::draw(FloatRect rect) {
	if(rect.width == -1) rect.width = m_width;
	if(rect.height == -1) rect.height = m_height;
	
	setPosRect(rect);
	
	draw();
}

void Image::draw() {
	GLfloat vertices[] = {
		m_posRect.x,                   m_posRect.y,
		m_posRect.x + m_posRect.width, m_posRect.y,
		m_posRect.x + m_posRect.width, m_posRect.y + m_posRect.height,
		m_posRect.x,                   m_posRect.y + m_posRect.height
	};
	
	FloatRect texRect = FloatRect(
		m_clipRect.x / float(m_width),
		m_clipRect.y / float(m_height),
		m_clipRect.width / float(m_width),
		m_clipRect.height / float(m_height)
	);
	
	GLfloat texCoords[] = {
		texRect.x,                 texRect.y,
		texRect.x + texRect.width, texRect.y,
		texRect.x + texRect.width, texRect.y + texRect.height,
		texRect.x,                 texRect.y + texRect.height
	};
	
	GLfloat colorMod[] = {
		m_colorMod.r, m_colorMod.g, m_colorMod.b, m_colorMod.a,
		m_colorMod.r, m_colorMod.g, m_colorMod.b, m_colorMod.a,
		m_colorMod.r, m_colorMod.g, m_colorMod.b, m_colorMod.a,
		m_colorMod.r, m_colorMod.g, m_colorMod.b, m_colorMod.a
	};
	
	GLubyte indices[] = {
		0, 1, 3,
		3, 1, 2
	};
	
	Shader::currentShader->setUniform("u_paletteID", m_paletteID);
	
	Shader::currentShader->enableVertexAttribArray("coord2d");
	Shader::currentShader->enableVertexAttribArray("texCoord");
	Shader::currentShader->enableVertexAttribArray("colorMod");
	
	glVertexAttribPointer(Shader::currentShader->attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(Shader::currentShader->attrib("texCoord"), 2, GL_FLOAT, GL_FALSE, 0, texCoords);
	glVertexAttribPointer(Shader::currentShader->attrib("colorMod"), 4, GL_FLOAT, GL_FALSE, 0, colorMod);
	
	Texture::bind(m_texture);
	
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	
	Texture::bind(nullptr);
	
	Shader::currentShader->disableVertexAttribArray("colorMod");
	Shader::currentShader->disableVertexAttribArray("texCoord");
	Shader::currentShader->disableVertexAttribArray("coord2d");
	
	Shader::currentShader->setUniform("u_paletteID", 0);
}

