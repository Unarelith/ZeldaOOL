/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 14:16:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "XMLFile.hpp"
#include "Application.hpp"
#include "Map.hpp"

Map::Map() {
}

Map::Map(std::string filename, Image &tileset) {
	load(filename, tileset);
}

Map::~Map() {
	delete[] m_data;
}

bool Map::load(std::string filename, Image &tileset) {
	m_tileset = tileset.getTexture();
	
	XMLFile doc(filename);
	
	XMLElement *mapElement = doc.FirstChildElement("map").ToElement();
	
	m_width = mapElement->IntAttribute("width");
	m_height = mapElement->IntAttribute("height");
	
	m_tileWidth = mapElement->IntAttribute("tilewidth");
	m_tileHeight = mapElement->IntAttribute("tileheight");
	
	m_data = new s16[m_width * m_height];
	
	u16 i = 0;
	XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		m_data[i++] = tileElement->IntAttribute("gid") - 1;
		
		tileElement = tileElement->NextSiblingElement("tile");
	}
	
	update();
	
	return true;
}

void Map::update() {
	m_vertices.setPrimitiveType(sf::Triangles);
	m_vertices.resize(m_width * m_height * 6);
	
	for(u16 y = 1 ; y < m_height + 1 ; y++) {
		for(u16 x = 0 ; x < m_width ; x++) {
			s16 tileNb = m_data[x + (y - 1) * m_width];
			
			if(tileNb == -1) continue;
			
			u16 tilesetX = tileNb % (m_tileset.getSize().x / m_tileWidth);
			u16 tilesetY = tileNb / (m_tileset.getSize().x / m_tileWidth);
			
			sf::Vertex *triangle = &m_vertices[(x + (y - 1) * m_width) * 6];
			
			triangle[0].position = sf::Vector2f(x * m_tileWidth, y * m_tileHeight);
			triangle[1].position = sf::Vector2f((x + 1) * m_tileWidth, y * m_tileHeight);
			triangle[2].position = sf::Vector2f(x * m_tileWidth, (y + 1) * m_tileHeight);
			triangle[3].position = triangle[1].position;
			triangle[4].position = triangle[2].position;
			triangle[5].position = sf::Vector2f((x + 1) * m_tileWidth, (y + 1) * m_tileHeight);
			
			triangle[0].texCoords = sf::Vector2f(tilesetX * m_tileWidth, tilesetY * m_tileHeight);
			triangle[1].texCoords = sf::Vector2f((tilesetX + 1) * m_tileWidth, tilesetY * m_tileHeight);
			triangle[2].texCoords = sf::Vector2f(tilesetX * m_tileWidth, (tilesetY + 1) * m_tileHeight);
			triangle[3].texCoords = triangle[1].texCoords;
			triangle[4].texCoords = triangle[2].texCoords;
			triangle[5].texCoords = sf::Vector2f((tilesetX + 1) * m_tileWidth, (tilesetY + 1) * m_tileHeight);
		}
	}
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	states.texture = &m_tileset;
	
	target.draw(m_vertices, states);
}

