/*
 * =====================================================================================
 *
 *       Filename:  Image.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 20:52:44
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "Image.hpp"
#include "ResourceHandler.hpp"

Image::Image() {
}

Image::Image(std::string filename) {
	load(filename);
}

Image::~Image() {
}

void Image::load(std::string filename) {
	m_texture = &ResourceHandler::getInstance().get<sf::Texture>(filename);
	
	setTexture(*m_texture);
	setClipRect(0, 0, width(), height());
}

void Image::setClipRect(s16 x, s16 y, u16 width, u16 height) {
	setTextureRect(sf::IntRect(x, y, width, height));
}

void Image::draw() {
	Application::getInstance().window().draw(*this);
}

void Image::draw(float x, float y, s16 width, s16 height) {
	setPosition(x, y);
	
	if(width == -1) width = getTextureRect().width;
	if(height == -1) height = getTextureRect().height;
	
	setScale(float(width) / float(getTextureRect().width), float(height) / float(getTextureRect().height));
	
	draw();
}

