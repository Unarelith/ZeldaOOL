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
#include "Exception.hpp"
#include "ResourceHandler.hpp"
#include "TileMap.hpp"
#include "TilesData.hpp"
#include "XMLFile.hpp"

sf::View TileMap::view(sf::FloatRect(0, -16, 160, 144));

TileMap::TileMap() {
}

TileMap::TileMap(std::string filename, std::string tilesetName) {
	load(filename, tilesetName);
}

TileMap::~TileMap() {
}

void TileMap::load(std::string filename, std::string tilesetName) {
	m_tileset = &ResourceHandler::getInstance().get<Tileset>(tilesetName);
	
	XMLFile doc(filename);
	
	XMLElement *mapElement = doc.FirstChildElement("map").ToElement();
	
	m_width = mapElement->IntAttribute("width");
	m_height = mapElement->IntAttribute("height");
	
	m_tileWidth = mapElement->IntAttribute("tilewidth");
	m_tileHeight = mapElement->IntAttribute("tileheight");
	
	XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		m_data.push_back(tileElement->IntAttribute("gid") - 1);
		
		tileElement = tileElement->NextSiblingElement("tile");
	}
	
	m_vertices.setPrimitiveType(sf::Triangles);
	m_vertices.resize(m_width * m_height * 6);
}

void TileMap::updateTile(u16 tileX, u16 tileY) {
	s16 tileNb = getTile(tileX, tileY);
	
	if(tileNb == -1) return;
	
	u16 tilesetX = tileNb % (m_tileset->texture().getSize().x / m_tileWidth);
	u16 tilesetY = tileNb / (m_tileset->texture().getSize().x / m_tileWidth);
	
	sf::Vertex *triangle = &m_vertices[(tileX + tileY * m_width) * 6];
	
	triangle[0].position = sf::Vector2f(tileX * m_tileWidth, tileY * m_tileHeight);
	triangle[1].position = sf::Vector2f((tileX + 1) * m_tileWidth, tileY * m_tileHeight);
	triangle[2].position = sf::Vector2f(tileX * m_tileWidth, (tileY + 1) * m_tileHeight);
	triangle[3].position = triangle[1].position;
	triangle[4].position = triangle[2].position;
	triangle[5].position = sf::Vector2f((tileX + 1) * m_tileWidth, (tileY + 1) * m_tileHeight);
	
	triangle[0].texCoords = sf::Vector2f(tilesetX * m_tileWidth, tilesetY * m_tileHeight);
	triangle[1].texCoords = sf::Vector2f((tilesetX + 1) * m_tileWidth, tilesetY * m_tileHeight);
	triangle[2].texCoords = sf::Vector2f(tilesetX * m_tileWidth, (tilesetY + 1) * m_tileHeight);
	triangle[3].texCoords = triangle[1].texCoords;
	triangle[4].texCoords = triangle[2].texCoords;
	triangle[5].texCoords = sf::Vector2f((tilesetX + 1) * m_tileWidth, (tilesetY + 1) * m_tileHeight);
}

void TileMap::updateTiles() {
	for(s16 tileY = 0 ; tileY < m_height ; tileY++) {
		for(s16 tileX = 0 ; tileX < m_width ; tileX++) {
			updateTile(tileX, tileY);
		}
	}
}

s16 TileMap::getTile(s16 tileX, s16 tileY) {
	if(tileX + tileY * m_width >= m_width * m_height
	|| tileX + tileY * m_width < 0) {
		return 1;
	} else {
		return m_data[tileX + tileY * m_width];
	}
}

void TileMap::setTile(u16 tileX, u16 tileY, u16 tile) {
	if(tileX + tileY * m_width >= m_width * m_height) {
		throw EXCEPTION("Tile coordinates out of map");
	}
	else if(tile != m_data[tileX + tileY * m_width]) {
		m_data[tileX + tileY * m_width] = tile;
		TileMap::updateTile(tileX, tileY);
	}
}

bool TileMap::passable(float x, float y) {
	s16 tile = m_tileset->info()[getTile(x / m_tileWidth, y / m_tileHeight)];
	return TilesData::infos[tile][((int)x & 0xF) / m_tileWidth + ((int)y & 0xF) / m_tileHeight * 2] != 1;
}

void TileMap::draw() {
	Application::getInstance().window().draw(*this);
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	states.texture = &m_tileset->texture();
	
	target.setView(view);
	
	target.draw(m_vertices, states);
	
	target.setView(target.getDefaultView());
}

