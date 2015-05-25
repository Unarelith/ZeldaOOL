/*
 * =====================================================================================
 *
 *       Filename:  MapRenderer.cpp
 *
 *    Description:  
 *
 *        Created:  30/04/2015 19:47:26
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "MapRenderer.hpp"
#include "Shader.hpp"
#include "VertexAttribute.hpp"

void MapRenderer::init(u16 mapWidth, u16 mapHeight) {
	VertexBuffer::bind(&m_vbo);
	
	m_vbo.setData(sizeof(VertexAttribute) * mapWidth * mapHeight * 6, nullptr, GL_DYNAMIC_DRAW);
	
	VertexBuffer::bind(nullptr);
}

void MapRenderer::updateTile(Vector2u16 tile, u16 id, Map &map) {
	VertexBuffer::bind(&m_vbo);
	
	float tileWidth  = map.tileset().tileWidth();
	float tileHeight = map.tileset().tileHeight();
	
	float x = tile.x * tileWidth;
	float y = tile.y * tileHeight;
	
	float texTileX = id % u16(map.tileset().width() / tileWidth) * tileWidth  / map.tileset().width();
	float texTileY = id / u16(map.tileset().width() / tileWidth) * tileHeight / map.tileset().height();
	
	float texTileWidth  = tileWidth  / map.tileset().width();
	float texTileHeight = tileHeight / map.tileset().height();
	
	VertexAttribute attributes[] = {
		{{x            , y             },    {texTileX               , texTileY                },    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y             },    {texTileX + texTileWidth, texTileY                },    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight},    {texTileX + texTileWidth, texTileY + texTileHeight},    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y             },    {texTileX               , texTileY                },    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight},    {texTileX + texTileWidth, texTileY + texTileHeight},    {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y + tileHeight},    {texTileX               , texTileY + texTileHeight},    {1.0f, 1.0f, 1.0f, 1.0f}}
	};
	
	m_vbo.updateData(sizeof(attributes) * (tile.x + tile.y * map.rect().width), sizeof(attributes), attributes);
	
	VertexBuffer::bind(nullptr);
}

void MapRenderer::draw(Map &map) {
	Shader::currentShader->enableVertexAttribArray("coord2d");
	Shader::currentShader->enableVertexAttribArray("texCoord");
	Shader::currentShader->enableVertexAttribArray("colorMod");
	
	VertexBuffer::bind(&m_vbo);
	
	glVertexAttribPointer(Shader::currentShader->attrib("coord2d"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), 0);
	glVertexAttribPointer(Shader::currentShader->attrib("texCoord"), 2, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*)offsetof(VertexAttribute, texCoord));
	glVertexAttribPointer(Shader::currentShader->attrib("colorMod"), 4, GL_FLOAT, GL_FALSE, sizeof(VertexAttribute), (GLvoid*)offsetof(VertexAttribute, colorMod));
	
	Texture::bind(&map.tileset());
	
	glDrawArrays(GL_TRIANGLES, 0, 6 * map.rect().width * map.rect().height);
	
	Texture::bind(nullptr);
	
	VertexBuffer::bind(nullptr);
	
	Shader::currentShader->disableVertexAttribArray("colorMod");
	Shader::currentShader->disableVertexAttribArray("texCoord");
	Shader::currentShader->disableVertexAttribArray("coord2d");
}

