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
#include "Config.hpp"
#include "XMLFile.hpp"
#include "Application.hpp"
#include "Map.hpp"

Map::Map() {
}

Map::Map(std::string filename, Tileset &tileset, u16 area, u16 x, u16 y) {
	load(filename, tileset, area, x, y);
}

Map::~Map() {
}

bool Map::load(std::string filename, Tileset &tileset, u16 area, u16 x, u16 y) {
	m_tileset = tileset;
	
	m_area = area;
	
	m_x = x;
	m_y = y;
	
	XMLFile doc(filename);
	
	XMLElement *mapElement = doc.FirstChildElement("map").ToElement();
	
	m_width = mapElement->IntAttribute("width");
	m_height = mapElement->IntAttribute("height");
	
	m_tileWidth = mapElement->IntAttribute("tilewidth");
	m_tileHeight = mapElement->IntAttribute("tileheight");
	
	XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		m_baseData.push_back(tileElement->IntAttribute("gid") - 1);
		
		tileElement = tileElement->NextSiblingElement("tile");
	}
	
	m_data = m_baseData;
	
	update();
	
	return true;
}

void Map::update(s16 offsetX, s16 offsetY) {
	m_vertices.setPrimitiveType(sf::Triangles);
	m_vertices.resize(m_width * m_height * 6);
	
	for(s16 y = offsetY + 1 ; y < m_height + offsetY + 1 ; y++) {
		for(s16 x = offsetX ; x < m_width + offsetX ; x++) {
			s16 tileNb = m_data[x + (y - 1) * m_width];
			
			if(tileNb == -1) continue;
			
			u16 tilesetX = tileNb % (m_tileset.texture.getSize().x / m_tileWidth);
			u16 tilesetY = tileNb / (m_tileset.texture.getSize().x / m_tileWidth);
			
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

void Map::draw() {
	Application::window.draw(*this);
}

void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform();
	
	states.texture = &m_tileset.texture;
	
	target.draw(m_vertices, states);
}

u16 Map::getTile(u16 tileX, u16 tileY) {
	if(tileX + (tileY - 1) * m_width < (u16)m_data.size()) {
		return m_data[tileX + (tileY - 1) * m_width];
	} else {
		return 0;
	}
}

