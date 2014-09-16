/*
 * =====================================================================================
 *
 *       Filename:  Image.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 19:48:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "Debug.hpp"
#include "Image.hpp"

Image::Image() {
}

Image::Image(const Image &image) {
	load(image.m_filename);
	
	m_clipRect.x = image.m_clipRect.x;
	m_clipRect.y = image.m_clipRect.y;
	m_clipRect.w = image.m_clipRect.w;
	m_clipRect.h = image.m_clipRect.h;
	
	m_posRect.x = image.m_posRect.x;
	m_posRect.y = image.m_posRect.y;
	m_posRect.w = image.m_posRect.w;
	m_posRect.h = image.m_posRect.h;
}

Image::Image(std::string filename) {
	load(filename);
}

Image::~Image() {
	SDL_DestroyTexture(m_texture);
}

void Image::load(std::string filename) {
	m_filename = filename;
	
	m_texture = IMG_LoadTexture(Application::window.renderer(), m_filename.c_str());
	if(!m_texture) {
		error("Failed to load image \"%s\": %s\n", m_filename.c_str(), IMG_GetError());
		exit(EXIT_FAILURE);
	}
	
	SDL_QueryTexture(m_texture, nullptr, nullptr, (int*)&m_width, (int*)&m_height);
	
	SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);
	
	setClipRect(0, 0, m_width, m_height);
	setPosRect(0, 0, m_width, m_height);
}

void Image::setClipRect(s16 x, s16 y, u16 width, u16 height) {
	m_clipRect.x = x;
	m_clipRect.y = y;
	m_clipRect.w = width;
	m_clipRect.h = height;
}

void Image::setPosRect(s16 x, s16 y, u16 width, u16 height) {
	m_posRect.x = x;
	m_posRect.y = y;
	m_posRect.w = width;
	m_posRect.h = height;
}

void Image::draw(s16 x, s16 y, s16 width, s16 height) {
	if(width == -1) width = m_width;
	if(height == -1) height = m_height;
	
	setPosRect(x + Application::window.currentView().x(),
			   y + Application::window.currentView().y(),
			   width, height);
	
	SDL_RenderCopy(Application::window.renderer(), m_texture, &m_clipRect, &m_posRect);
}

