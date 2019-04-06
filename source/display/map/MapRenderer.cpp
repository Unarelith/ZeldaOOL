/*
 * =====================================================================================
 *
 *       Filename:  TilemapRenderer.cpp
 *
 *    Description:
 *
 *        Created:  15/02/2019 19:21:11
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include "Map.hpp"
#include "MapRenderer.hpp"

void MapRenderer::init(Map *map, u16 mapWidth, u16 mapHeight) {
	m_map = map;

	m_vbo.setPrimitiveType(sf::PrimitiveType::Triangles);
	m_vbo.create(mapWidth * mapHeight * 6);
	m_vbo.setUsage(sf::VertexBuffer::Dynamic);
}

void MapRenderer::updateTile(u16 tileX, u16 tileY, u16 id, Map &map) {
	if (id == 0) return;

	float tileWidth  = map.tileset().tileWidth();
	float tileHeight = map.tileset().tileHeight();

	float x = tileX * tileWidth;
	float y = tileY * tileHeight;

	float texTileX = id % u16(map.tileset().getSize().x / tileWidth) * tileWidth;
	float texTileY = id / u16(map.tileset().getSize().x / tileWidth) * tileHeight;

	float texTileWidth  = tileWidth;
	float texTileHeight = tileHeight;

	sf::Vertex vertices[6] = {
		{{x            , y             }, sf::Color::White, {texTileX               , texTileY                }},
		{{x + tileWidth, y             }, sf::Color::White, {texTileX + texTileWidth, texTileY                }},
		{{x + tileWidth, y + tileHeight}, sf::Color::White, {texTileX + texTileWidth, texTileY + texTileHeight}},
		{{x            , y             }, sf::Color::White, {texTileX               , texTileY                }},
		{{x + tileWidth, y + tileHeight}, sf::Color::White, {texTileX + texTileWidth, texTileY + texTileHeight}},
		{{x            , y + tileHeight}, sf::Color::White, {texTileX               , texTileY + texTileHeight}}
	};

	m_vbo.update(vertices, 6, 6 * (tileX + tileY * map.width()));
}

void MapRenderer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	if (!m_map) return;

	states.texture = &m_map->tileset();

	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	target.draw(m_vbo, 0, 6 * m_map->width() * m_map->height(), states);
	// glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

