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
#include "ShaderManager.hpp"
#include "TileMap.hpp"
#include "VertexAttribute.hpp"

TileMap::TileMap() {
}

TileMap::TileMap(Texture &texture, u16 width, u16 height, s16 *data) {
	load(texture, width, height, data);
}

TileMap::~TileMap() {
	glDeleteBuffers(1, &m_vbo);
}

void TileMap::load(Texture &texture, u16 width, u16 height, s16 *data) {
	m_texture = &texture;
	
	m_width = width;
	m_height = height;
	
	glGenBuffers(1, &m_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
	m_data = data;
	
	glBufferData(GL_ARRAY_BUFFER, sizeof(VertexAttribute) * m_width * m_height * 6, NULL, GL_DYNAMIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	m_view.load(0, 16, WINDOW_WIDTH, WINDOW_HEIGHT - 16);
}

void TileMap::updateTile(float x, float y, u16 id) {
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
	float texTileX = id % (m_texture->width() / 16) * 16.0f / m_texture->width();
	float texTileY = id / (m_texture->width() / 16) * 16.0f / m_texture->height();
	
	float tileWidth = 16.0f / m_texture->width();
	float tileHeight = 16.0f / m_texture->height();
	
	VertexAttribute attributes[] = {	
		{{x		   , y		  },	{texTileX			 , texTileY},					{1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + 16.0f, y		  },	{texTileX + tileWidth, texTileY},					{1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + 16.0f, y + 16.0f},	{texTileX + tileWidth, texTileY + tileHeight},		{1.0f, 1.0f, 1.0f, 1.0f}},
		{{x		   , y		  },	{texTileX			 , texTileY},					{1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + 16.0f, y + 16.0f},	{texTileX + tileWidth, texTileY + tileHeight},		{1.0f, 1.0f, 1.0f, 1.0f}},
		{{x		   , y + 16.0f},	{texTileX			 , texTileY + tileHeight},		{1.0f, 1.0f, 1.0f, 1.0f}}
	};
	
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(attributes) * (x / 16 + (y / 16) * m_width), sizeof(attributes), attributes);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void TileMap::draw() {
	m_view.enable();
	
	ShaderManager::currentShader().enableVertexAttribArray("coord2d");
	ShaderManager::currentShader().enableVertexAttribArray("texCoord");
	ShaderManager::currentShader().enableVertexAttribArray("colorMod");
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
	glVertexAttribPointer(ShaderManager::currentShader().attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), 0);
	glVertexAttribPointer(ShaderManager::currentShader().attrib("texCoord"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*) offsetof(VertexAttribute, texCoord));
	glVertexAttribPointer(ShaderManager::currentShader().attrib("colorMod"), 4, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*) offsetof(VertexAttribute, colorMod));
	
	Texture::bind(m_texture);
	
	glDrawArrays(GL_TRIANGLES, 0, 6 * m_width * m_height);
	
	Texture::bind(nullptr);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	ShaderManager::currentShader().disableVertexAttribArray("colorMod");
	ShaderManager::currentShader().disableVertexAttribArray("texCoord");
	ShaderManager::currentShader().disableVertexAttribArray("coord2d");
	
	m_view.disable();
}

