/*
 * =====================================================================================
 *
 *       Filename:  TileMap.cpp
 *
 *    Description:
 *
 *        Created:  08/04/2018 19:29:39
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "TileMap.hpp"
#include "Vertex.hpp"

TileMap::TileMap(u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data) : m_tileset(tileset) {
	m_width = width;
	m_height = height;

	m_data = data;
	m_tileAnimations.assign(m_data.size(), {});

	VertexBuffer::bind(&m_vbo);
	m_vbo.setData(sizeof(Vertex) * m_width * m_height * 6, nullptr, GL_DYNAMIC_DRAW);
	VertexBuffer::bind(nullptr);

	for (u16 x = 0 ; x < m_width ; ++x) {
		for (u16 y = 0 ; y < m_height ; ++y) {
			updateTile(x, y, m_data.at(x + y * m_width));
		}
	}
}

void TileMap::updateAnimations() {
	for (size_t i = 0 ; i < m_data.size() ; ++i) {
		const Tile &tile = m_tileset.getTile(m_data.at(i));
		if (tile.getFrameCount()) {
			TileAnimation &tileAnimation = m_tileAnimations.at(i);
			if (!tileAnimation.timer.isStarted())
				tileAnimation.timer.start();

			if (tileAnimation.timer.time() > tile.getFrame(tileAnimation.currentFrame).duration) {
				tileAnimation.currentFrame++;
				tileAnimation.currentFrame %= tile.getFrameCount();

				updateTile(i % m_width, i / m_width, tile.getFrame(tileAnimation.currentFrame).tileID);

				tileAnimation.timer.reset();
				tileAnimation.timer.start();
			}
		}
	}
}

u16 TileMap::getTile(u16 tileX, u16 tileY) const {
	if (tileX + tileY * m_width < m_width * m_height) {
		return m_data[tileX + tileY * m_width];
	} else {
		return 0;
	}
}

const Tile &TileMap::getTileInfo(float x, float y) const {
	return m_tileset.getTile(getTile(x / m_tileset.tileWidth(), y / m_tileset.tileHeight()));
}

void TileMap::updateTile(u16 tileX, u16 tileY, u16 id) {
	float tileWidth  = m_tileset.tileWidth();
	float tileHeight = m_tileset.tileHeight();

	float x = tileX * tileWidth;
	float y = tileY * tileHeight;

	float texTileX = id % u16(m_tileset.texture().width() / tileWidth) * tileWidth  / m_tileset.texture().width();
	float texTileY = id / u16(m_tileset.texture().width() / tileWidth) * tileHeight / m_tileset.texture().height();

	float texTileWidth  = tileWidth  / m_tileset.texture().width();
	float texTileHeight = tileHeight / m_tileset.texture().height();

	Vertex vertices[] = {
		{{x            , y             , 0, 1}, {texTileX               , texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y             , 0, 1}, {texTileX + texTileWidth, texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight, 0, 1}, {texTileX + texTileWidth, texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y             , 0, 1}, {texTileX               , texTileY                }, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x + tileWidth, y + tileHeight, 0, 1}, {texTileX + texTileWidth, texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}},
		{{x            , y + tileHeight, 0, 1}, {texTileX               , texTileY + texTileHeight}, {1.0f, 1.0f, 1.0f, 1.0f}}
	};

	VertexBuffer::bind(&m_vbo);
	m_vbo.updateData(sizeof(vertices) * (tileX + tileY * m_width), sizeof(vertices), vertices);
	VertexBuffer::bind(nullptr);
}

void TileMap::draw(RenderTarget &target, RenderStates states) const {
	applyTransform(states);
	states.texture = &m_tileset.texture();

	target.draw(m_vbo, GL_TRIANGLES, 0, 6 * m_width * m_height, states);
}

