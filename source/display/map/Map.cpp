/*
 * =====================================================================================
 *
 *       Filename:  Map.cpp
 *
 *    Description:
 *
 *        Created:  30/04/2015 19:45:20
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "MapLoader.hpp"
#include "ResourceHandler.hpp"
#include "TilesInfos.hpp"

Map *Map::currentMap = nullptr;

Map::Map(u16 area, u16 x, u16 y, u16 width, u16 height, Tileset &tileset, const std::vector<u16> &data) : m_tileset(tileset) {
	m_area = area;
	m_x = x;
	m_y = y;

	m_width = width;
	m_height = height;

	m_baseData = data;
	m_data = m_baseData;

	setPosition(0, 16);

	m_renderer.init(this, m_width, m_height);

	updateTiles();
}

void Map::reset() {
	m_data = m_baseData;

	m_scene.reset();
}

void Map::update() {
	m_animator.animateTiles(*this);

	m_scene.update();
}

void Map::draw(RenderTarget &target, RenderStates states) const {
	applyTransform(states);

	target.draw(m_renderer, states);

	target.draw(m_scene, states);
}

void Map::updateTiles() {
	for(u16 tileY = 0 ; tileY < m_height ; tileY++) {
		for(u16 tileX = 0 ; tileX < m_width ; tileX++) {
			u16 tileID = getTile(tileX, tileY);

			m_renderer.updateTile(tileX, tileY, tileID, *this);
			m_animator.updateTile(tileX, tileY, tileID, m_tileset);
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

void Map::setTile(u16 tileX, u16 tileY, u16 id, bool persistent) {
	if(tileX + tileY * m_width < m_width * m_height) {
		m_data[tileX + tileY * m_width] = id;

		if(persistent) m_baseData[tileX + tileY * m_width] = id;
	}

	m_renderer.updateTile(tileX, tileY, id, *this);
}

bool Map::passable(float x, float y) {
	s16 tile = m_tileset.info()[getTile(x / m_tileset.tileWidth(),
	                                    y / m_tileset.tileHeight())];

	return TilesInfos::infos[tile][(s16(x) & 0xF) / (m_tileset.tileWidth()  / 2)
	                             + (s16(y) & 0xF) / (m_tileset.tileHeight() / 2) * 2] != TilesInfos::SubTileType::NonPassable;
}

bool Map::onDoor(float x, float y) {
	s16 tile = m_tileset.info()[getTile(x / m_tileset.tileWidth(),
	                                    y / m_tileset.tileHeight())];

	return TilesInfos::infos[tile][(s16(x) & 0xF) / (m_tileset.tileWidth()  / 2)
	                             + (s16(y) & 0xF) / (m_tileset.tileHeight() / 2) * 2] == TilesInfos::SubTileType::ChangeMap;
}

bool Map::isTile(float x, float y, u16 tile) {
	return m_tileset.info()[getTile(x / m_tileset.tileWidth(),
	                                y / m_tileset.tileHeight())] == tile;
}

Map &Map::getMap(u16 area, u16 mapX, u16 mapY) {
	return ResourceHandler::getInstance().get<Map>(MapLoader::makeName(area, mapX, mapY));
}

bool Map::mapExists(u16 area, u16 mapX, u16 mapY) {
	return ResourceHandler::getInstance().has(MapLoader::makeName(area, mapX, mapY));
}

