/*
 * =====================================================================================
 *
 *       Filename:  Tileset.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2015 16:03:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Tileset.hpp"

Tileset::Tileset(Tileset &&tileset) : m_anims(std::move(tileset.m_anims)) {
	m_info = tileset.m_info;
	
	m_tileWidth = tileset.m_tileWidth;
	m_tileHeight = tileset.m_tileHeight;
}

Tileset::Tileset(const std::string &filename, u16 *info, u16 tileWidth, u16 tileHeight) {
	load(filename, info, tileWidth, tileHeight);
}

void Tileset::load(const std::string &filename, u16 *info, u16 tileWidth, u16 tileHeight) {
	Texture::load(filename);
	
	m_info = info;
	
	m_tileWidth  = tileWidth;
	m_tileHeight = tileHeight;
}

void Tileset::addAnimation(std::vector<u16> &frames, u16 delay) {
	m_anims.emplace_back(delay);
	
	for(u16 it : frames) {
		m_anims.back().frames.push_back(it);
	}
}

