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

Image::Image(std::string filename) {
	load(filename);
}

Image::~Image() {
	SDL_DestroyTexture(m_texture);
}

void Image::load(std::string filename) {
	m_filename = filename;
	
	SDL_RWops *image = SDL_RWFromFile(filename.c_str(), "rb");
	SDL_Surface *surface = IMG_Load_RW(image, 1);
	
	if(!surface) {
		error("Failed to load image \"%s\": %s\n", filename.c_str(), IMG_GetError());
		exit(EXIT_FAILURE);
	}
	
	m_width = surface->w;
	m_height = surface->h;
	
	m_texture = SDL_CreateTextureFromSurface(Application::window.renderer(), surface);
	if(!m_texture) {
		error("Failed to create texture from image: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	SDL_FreeSurface(surface);
	
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
	m_clipRect.x = x;
	m_clipRect.y = y;
	m_clipRect.w = width;
	m_clipRect.h = height;
}

void Image::draw(s16 x, s16 y, s16 width, s16 height) {
	if(width == -1) width = m_width;
	if(height == -1) height = m_height;
	
	setPosRect(x, y, width, height);
	
	SDL_RenderCopy(Application::window.renderer(), m_texture, &m_clipRect, &m_posRect);
}

