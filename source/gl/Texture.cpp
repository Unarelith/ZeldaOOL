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
}

Texture::Texture(std::string filename) {
	load(filename);
}

Texture::~Texture() {
}

void Texture::load(std::string filename) {
	m_filename = filename;
	
	SDL_Surface *surface = IMG_Load(filename.c_str());
	if(!surface) {
		error("Failed to load texture: %s", filename.c_str());
		exit(EXIT_FAILURE);
	}
	
	m_width = surface->w;
	m_height = surface->h;
	
	glGenTextures(1, &m_texture);
	
	bind();
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
	
	unbind();
	
	SDL_FreeSurface(surface);
	
	m_uniform = Application::window.defaultShader()->uniform("tex");
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, m_texture);
	glUniform1i(m_uniform, 0);
}

