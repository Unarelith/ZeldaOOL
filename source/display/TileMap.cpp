/*
 * =====================================================================================
 *
 *       Filename:  TileMap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/12/2014 19:53:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "ResourceHandler.hpp"
#include "TileMap.hpp"

TileMap::TileMap() {
}

TileMap::TileMap(std::string tilesetName, u16 width, u16 height, s16 *data) {
	load(tilesetName, width, height, data);
}

TileMap::~TileMap() {
}

void TileMap::load(std::string tilesetName, u16 width, u16 height, s16 *data) {
	m_tileset = &ResourceHandler::getInstance().get<Tileset>(tilesetName);
	
	m_width = width;
	m_height = height;
	
	m_data = data;
}

u16 TileMap::getTile(s16 tileX, s16 tileY) {
	if(tileX + tileY * m_width >= m_width * m_height
	|| tileX + tileY * m_width < 0) {
		return 1;
	} else {
		return m_data[tileX + tileY * m_width];
	}
}

void TileMap::setTile(u16 tileX, u16 tileY, u16 tile) {
	if(tileX + tileY * m_width >= m_width * m_height) {
		throw std::string("Tile coordinates out of map");
	} else {
		m_data[tileX + tileY * m_width] = tile;
	}
}

void TileMap::draw() {
	Application::getInstance().window().draw(*this);
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	states.texture = &m_tileset->texture;
	
	target.draw(m_vertices, states);
}

