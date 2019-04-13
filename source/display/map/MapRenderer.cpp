/*
 * =====================================================================================
 *
 *       Filename:  MapRenderer.cpp
 *
 *    Description:
 *
 *        Created:  30/04/2015 19:47:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/gl/Shader.hpp>
#include <gk/gl/Vertex.hpp>

#include "Map.hpp"
#include "MapRenderer.hpp"

void MapRenderer::init(Map *map, u16 mapWidth, u16 mapHeight) {
	m_map = map;

	gk::VertexBuffer::bind(&m_vbo);
	m_vbo.setData(sizeof(gk::Vertex) * mapWidth * mapHeight * 6, nullptr, GL_DYNAMIC_DRAW);
	gk::VertexBuffer::bind(nullptr);
}

void MapRenderer::updateTile(u16 tileX, u16 tileY, u16 id, Map &map) {
	gk::VertexBuffer::bind(&m_vbo);

	float tileWidth  = map.tileset().tileWidth();
	float tileHeight = map.tileset().tileHeight();

	float x = tileX * tileWidth;
	float y = tileY * tileHeight;

	float texTileX = id % u16(map.tileset().getSize().x / tileWidth) * tileWidth  / map.tileset().getSize().x;
	float texTileY = id / u16(map.tileset().getSize().y / tileWidth) * tileHeight / map.tileset().getSize().y;

	float texTileWidth  = tileWidth  / map.tileset().getSize().x;
	float texTileHeight = tileHeight / map.tileset().getSize().y;

	gk::Vertex vertices[] = {
		{{x            , y             , 0, 1}, {texTileX               , texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y             , 0, 1}, {texTileX + texTileWidth, texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight, 0, 1}, {texTileX + texTileWidth, texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y             , 0, 1}, {texTileX               , texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight, 0, 1}, {texTileX + texTileWidth, texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y + tileHeight, 0, 1}, {texTileX               , texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}}
	};

	m_vbo.updateData(sizeof(vertices) * (tileX + tileY * map.width()), sizeof(vertices), vertices);

	gk::VertexBuffer::bind(nullptr);
}

void MapRenderer::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	if (!m_map) return;

	states.texture = &m_map->tileset();

	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);

	target.draw(m_vbo, GL_TRIANGLES, 0, 6 * m_map->width() * m_map->height(), states);
}

