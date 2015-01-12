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
#include "Exception.hpp"
#include "Texture.hpp"

Texture::Texture() {
}

Texture::Texture(const std::string &filename) {
	load(filename);
}

void Texture::load(const std::string &filename) {
	m_filename = filename;
	
	SDL_Surface *surface = IMG_Load(filename.c_str());
	if(!surface) {
		throw EXCEPTION("Failed to load texture:", filename);
	}
	
	m_width = surface->w;
	m_height = surface->h;
	
	glGenTextures(1, &m_texture);
	
	bind(this);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
	
	bind(nullptr);
	
	SDL_FreeSurface(surface);
	
	m_paletteID = 0;
}

void Texture::bind(const Texture *texture) {
	if(texture) {
		glBindTexture(GL_TEXTURE_2D, texture->m_texture);
	} else {
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

