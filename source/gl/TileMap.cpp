/*
 * =====================================================================================
 *
 *       Filename:  TileMap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20/09/2014 15:28:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Config.hpp"
#include "Shader.hpp"
#include "TileMap.hpp"
#include "VertexAttribute.hpp"

TileMap::TileMap() {
}

TileMap::TileMap(Tileset &tileset, u16 width, u16 height, s16 *data) {
	load(tileset, width, height, data);
}

TileMap::~TileMap() {
}

void TileMap::load(Tileset &tileset, u16 width, u16 height, s16 *data) {
	m_tileset = &tileset;
	
	m_width = width;
	m_height = height;
	
	m_data = data;
	
	VertexBuffer::bind(&m_vbo);
	
	m_vbo.setData(sizeof(VertexAttribute) * m_width * m_height * 6, nullptr, GL_DYNAMIC_DRAW);
	
	VertexBuffer::bind(nullptr);
	
	m_view.load(0, 16, WINDOW_WIDTH, WINDOW_HEIGHT - 16);
}

void TileMap::updateTile(u16 tileX, u16 tileY, u16 id) {
	VertexBuffer::bind(&m_vbo);
	
	float tileWidth  = m_tileset->tileWidth;
	float tileHeight = m_tileset->tileHeight;
	
	float x = tileX * tileWidth;
	float y = tileY * tileHeight;
	
	float texTileX = id % u16(m_tileset->texture.width() / tileWidth) * tileWidth  / m_tileset->texture.width();
	float texTileY = id / u16(m_tileset->texture.width() / tileWidth) * tileHeight / m_tileset->texture.height();
	
	float texTileWidth  = tileWidth  / m_tileset->texture.width();
	float texTileHeight = tileHeight / m_tileset->texture.height();
	
	VertexAttribute attributes[] = {	
		{{x            , y             },    {texTileX               , texTileY},                    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y             },    {texTileX + texTileWidth, texTileY},                    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight},    {texTileX + texTileWidth, texTileY + texTileHeight},    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y             },    {texTileX               , texTileY},                    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight},    {texTileX + texTileWidth, texTileY + texTileHeight},    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y + tileHeight},    {texTileX               , texTileY + texTileHeight},    {1.0f, 1.0f, 1.0f, 1.0f}}
	};
	
	m_vbo.updateData(sizeof(attributes) * (tileX + tileY * m_width), sizeof(attributes), attributes);
	
	VertexBuffer::bind(nullptr);
}

void TileMap::draw() {
	Shader::currentShader->enableVertexAttribArray("coord2d");
	Shader::currentShader->enableVertexAttribArray("texCoord");
	Shader::currentShader->enableVertexAttribArray("colorMod");
	
	VertexBuffer::bind(&m_vbo);
	
	glVertexAttribPointer(Shader::currentShader->attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), 0);
	glVertexAttribPointer(Shader::currentShader->attrib("texCoord"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*) offsetof(VertexAttribute, texCoord));
	glVertexAttribPointer(Shader::currentShader->attrib("colorMod"), 4, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*) offsetof(VertexAttribute, colorMod));
	
	Texture::bind(&m_tileset->texture);
	
	glDrawArrays(GL_TRIANGLES, 0, 6 * m_width * m_height);
	
	Texture::bind(nullptr);
	
	VertexBuffer::bind(nullptr);
	
	Shader::currentShader->disableVertexAttribArray("colorMod");
	Shader::currentShader->disableVertexAttribArray("texCoord");
	Shader::currentShader->disableVertexAttribArray("coord2d");
}

u16 TileMap::getTile(u16 tileX, u16 tileY) {
	if(tileX + tileY * m_width < m_width * m_height) {
		return m_data[tileX + tileY * m_width];
	} else {
		return 0;
	}
}

void TileMap::setTile(u16 tileX, u16 tileY, u16 tile) {
	if(tileX + tileY * m_width < m_width * m_height) {
		m_data[tileX + tileY * m_width] = tile;
		
		TileMap::updateTile(tileX, tileY, tile);
	}
}

