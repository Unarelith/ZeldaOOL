/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
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

