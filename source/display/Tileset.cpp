/*
 * =====================================================================================
 *
 *       Filename:  Tileset.cpp
 *
 *    Description:
 *
 *        Created:  08/04/2018 19:49:59
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Tileset.hpp"

Tileset::Tileset(const std::string &name, u16 tileWidth, u16 tileHeight, u32 tileCount, Texture &texture) : m_texture(texture) {
	m_name = name;

	m_tileWidth = tileWidth;
	m_tileHeight = tileHeight;

	m_tiles.assign(tileCount, Tile{});
}

