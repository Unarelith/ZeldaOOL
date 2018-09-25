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
#include "Map.hpp"
#include "MapRenderer.hpp"
#include "Shader.hpp"
#include "Vertex.hpp"

void MapRenderer::init(Map *map, u16 mapWidth, u16 mapHeight) {
	m_map = map;

	VertexBuffer::bind(&m_vbo);
	m_vbo.setData(sizeof(Vertex) * mapWidth * mapHeight * 6, nullptr, GL_DYNAMIC_DRAW);
	VertexBuffer::bind(nullptr);
}

void MapRenderer::updateTile(u16 tileX, u16 tileY, u16 id, Map &map) {
	VertexBuffer::bind(&m_vbo);

	float tileWidth  = map.tileset().tileWidth();
	float tileHeight = map.tileset().tileHeight();

	float x = tileX * tileWidth;
	float y = tileY * tileHeight;

	float texTileX = id % u16(map.tileset().width() / tileWidth) * tileWidth  / map.tileset().width();
	float texTileY = id / u16(map.tileset().width() / tileWidth) * tileHeight / map.tileset().height();

	float texTileWidth  = tileWidth  / map.tileset().width();
	float texTileHeight = tileHeight / map.tileset().height();

	Vertex vertices[] = {
		{{x            , y             , 0, 1}, {texTileX               , texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y             , 0, 1}, {texTileX + texTileWidth, texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight, 0, 1}, {texTileX + texTileWidth, texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y             , 0, 1}, {texTileX               , texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight, 0, 1}, {texTileX + texTileWidth, texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y + tileHeight, 0, 1}, {texTileX               , texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}}
	};

	m_vbo.updateData(sizeof(vertices) * (tileX + tileY * map.width()), sizeof(vertices), vertices);

	VertexBuffer::bind(nullptr);
}

void MapRenderer::draw(RenderTarget &target, RenderStates states) const {
	if (!m_map) return;

	states.texture = &m_map->tileset();

	target.draw(m_vbo, GL_TRIANGLES, 0, 6 * m_map->width() * m_map->height(), states);
}

