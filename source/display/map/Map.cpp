/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 22:04:36
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Shader.hpp"
#include "Map.hpp"
#include "VertexAttribute.hpp"

Map::Map(u16 area, u16 x, u16 y, u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data) {
	load(area, x, y, width, height, tileset, data);
}

void Map::load(u16 area, u16 x, u16 y, u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data) {
	m_area = area;
	m_x = x;
	m_y = y;
	
	m_width = width;
	m_height = height;
	
	m_tileset = &tileset;
	
	m_baseData = data;
	m_data = data;
	
	m_view.reset(0, 0, m_width, m_height);
	
	VertexBuffer::bind(&m_vbo);
	
	m_vbo.setData(sizeof(VertexAttribute) * m_width * m_height * 6, nullptr, GL_DYNAMIC_DRAW);
	
	VertexBuffer::bind(nullptr);
	
	updateTiles();
}

void Map::updateTile(u16 tileX, u16 tileY, u16 id) {
	VertexBuffer::bind(&m_vbo);
	
	float tileWidth  = m_tileset->tileWidth();
	float tileHeight = m_tileset->tileHeight();
	
	float x = tileX * tileWidth;
	float y = tileY * tileHeight;
	
	float texTileX = id % u16(m_tileset->width() / tileWidth) * tileWidth  / m_tileset->width();
	float texTileY = id / u16(m_tileset->width() / tileWidth) * tileHeight / m_tileset->height();
	
	float texTileWidth  = tileWidth  / m_tileset->width();
	float texTileHeight = tileHeight / m_tileset->height();
	
	VertexAttribute attributes[] = {
		{{x            , y             },    {texTileX               , texTileY                },    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y             },    {texTileX + texTileWidth, texTileY                },    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight},    {texTileX + texTileWidth, texTileY + texTileHeight},    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y             },    {texTileX               , texTileY                },    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight},    {texTileX + texTileWidth, texTileY + texTileHeight},    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y + tileHeight},    {texTileX               , texTileY + texTileHeight},    {1.0f, 1.0f, 1.0f, 1.0f}}
	};
	
	m_vbo.updateData(sizeof(attributes) * (tileX + tileY * m_width), sizeof(attributes), attributes);
	
	VertexBuffer::bind(nullptr);
}

void Map::update() {
	m_mapAnimator.animateTiles(*this);
}

void Map::draw() {
	View::bind(&m_view);
	
	Shader::currentShader->enableVertexAttribArray("coord2d");
	Shader::currentShader->enableVertexAttribArray("texCoord");
	Shader::currentShader->enableVertexAttribArray("color");
	
	VertexBuffer::bind(&m_vbo);
	
	glVertexAttribPointer(Shader::currentShader->attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), 0);
	glVertexAttribPointer(Shader::currentShader->attrib("texCoord"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*)offsetof(VertexAttribute, texCoord));
	glVertexAttribPointer(Shader::currentShader->attrib("color"), 4, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*)offsetof(VertexAttribute, color));
	
	Texture::bind(m_tileset);
	
	glDrawArrays(GL_TRIANGLES, 0, 6 * m_width * m_height);
	
	Texture::bind(nullptr);
	
	VertexBuffer::bind(nullptr);
	
	Shader::currentShader->disableVertexAttribArray("color");
	Shader::currentShader->disableVertexAttribArray("texCoord");
	Shader::currentShader->disableVertexAttribArray("coord2d");
	
	View::bind(nullptr);
}

void Map::resetTiles() {
	m_data = m_baseData;
}

void Map::updateTiles() {
	for(u16 tileY = 0 ; tileY < m_height ; tileY++) {
		for(u16 tileX = 0 ; tileX < m_width ; tileX++) {
			u16 tileID = getTile(tileX, tileY);
			
			updateTile(tileX, tileY, tileID);
			m_mapAnimator.updateTile(tileX, tileY, tileID, m_tileset);
		}
	}
}

u16 Map::getTile(u16 tileX, u16 tileY) {
	if(tileX + tileY * m_width < m_width * m_height) {
		return m_data[tileX + tileY * m_width];
	} else {
		return 0;
	}
}

void Map::setTile(u16 tileX, u16 tileY, u16 id) {
	if(tileX + tileY * m_width < m_width * m_height) {
		m_data[tileX + tileY * m_width] = id;
	}
	
	Map::updateTile(tileX, tileY, id);
}

#include "MapLoader.hpp"
#include "ResourceHandler.hpp"

Map &Map::getMap(u16 area, u16 mapX, u16 mapY) {
	return ResourceHandler::getInstance().get<Map>(MapLoader::makeName(area, mapX, mapY));
}

