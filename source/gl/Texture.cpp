/*
 * =====================================================================================
 *
 *       Filename:  Texture.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2014 17:07:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include <SFML/Graphics/Image.hpp>

#include "Texture.hpp"

Texture::Texture() {
}

Texture::Texture(std::string filename) {
	load(filename);
}

Texture::~Texture() {
}

void Texture::load(std::string filename) {
	m_filename = filename;
	
	//if(!surface) {
	//	error("Failed to load texture: %s", filename.c_str());
	//	exit(EXIT_FAILURE);
	//}
	sf::Image image;
	image.loadFromFile(filename);
	
	// sf::Texture way
	image.flipHorizontally();
	image.flipVertically();
	
	m_width = image.getSize().x;
	m_height = image.getSize().y;
	
	glGenTextures(1, &m_texture);
	
	bind(this);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
	
	bind(nullptr);
}

void Texture::bind(const Texture *texture) {
	if(texture && texture->m_texture) {
		glBindTexture(GL_TEXTURE_2D, texture->m_texture);
	} else {
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

