/*
 * =====================================================================================
 *
 *       Filename:  Texture.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/09/2014 21:16:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Application.hpp"
#include "Debug.hpp"
#include "Texture.hpp"

Texture::Texture() {
}

Texture::Texture(const Texture &texture) {
	m_filename = texture.m_filename;
	
	m_width = texture.m_width;
	m_height = texture.m_height;
	
	m_texture = texture.m_texture;
	
	m_uniform = texture.m_uniform;
	
	m_comp = texture.m_comp;
	
	m_data = texture.m_data;
	
	m_isCopy = true;
}

Texture::Texture(std::string filename) {
	load(filename);
}

Texture::~Texture() {
	if(!m_isCopy) stbi_image_free(m_data);
}

void Texture::load(std::string filename) {
	m_filename = filename;
	
	m_data = stbi_load(filename.c_str(), &m_width, &m_height, &m_comp, 0);
	if(!m_data) {
		error("Failed to load texture: %s", filename.c_str());
		exit(EXIT_FAILURE);
	}
	
	glGenTextures(1, &m_texture);
	
	bind();
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	if(m_comp == 3) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, m_data);
	}
	else if(m_comp == 4) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
	}
	
	unbind();
	
	m_uniform = Application::window.defaultShader()->uniform("tex");
	
	m_isCopy = false;
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glUniform1i(m_uniform, 0);
}

