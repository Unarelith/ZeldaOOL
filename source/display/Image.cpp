/*
 * =====================================================================================
 *
 *       Filename:  Image.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/07/2014 14:43:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "Image.hpp"

Image::Image() {
}

Image::Image(const Image &image) {
	load(image.m_filename);
}

Image::Image(std::string filename) {
	load(filename);
}

Image::~Image() {
}

void Image::load(std::string filename) {
	m_filename = filename;
	
	m_texture.loadFromFile(filename);
	
	m_image.setTexture(m_texture);
	setClipRect(0, 0, width(), height());
}

void Image::setClipRect(u16 clipX, u16 clipY, u16 width, u16 height) {
	m_image.setTextureRect(sf::IntRect(clipX, clipY, width, height));
}

void Image::draw(s16 x, s16 y, s16 width, s16 height) {
	m_image.setPosition(x, y);
	
	if(width == -1) width = m_image.getTextureRect().width;
	if(height == -1) height = m_image.getTextureRect().height;
	
	m_image.setScale(float(width) / float(m_image.getTextureRect().width), float(height) / float(m_image.getTextureRect().height));
	
	Application::window.draw(m_image);
}

