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

Map::Map(u16 area, IntRect rect, Tileset &tileset, const std::vector<u16> &data) : m_tileset(tileset) {
	m_area = area;
	m_rect = rect;
	
	m_baseData = data;
	m_data = m_baseData;
	
	m_view.reset(0, 16, m_rect.width * tileset.tileWidth(), m_rect.height * tileset.tileHeight());
	
	m_renderer.init(m_rect.width, m_rect.height);
	
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

void Map::draw() {
	View::bind(&m_view);
	
	m_renderer.draw(*this);
	
	m_scene.draw();
	
	View::bind(nullptr);
}

void Map::updateTiles() {
	Vector2u16 tile = {0, 0};
	for(tile.y = 0 ; tile.y < m_rect.height ; tile.y++) {
		for(tile.x = 0 ; tile.x < m_rect.width ; tile.x++) {
			u16 tileID = getTile(tile);
			
			m_renderer.updateTile(tile, tileID, *this);
			m_animator.updateTile(tile, tileID, m_tileset);
		}
	}
}

u16 Map::getTile(Vector2u16 tile) {
	if(tile.x + tile.y * m_rect.width < m_rect.width * m_rect.height) {
		return m_data[tile.x + tile.y * m_rect.width];
	} else {
		return 0;
	}
}

void Map::setTile(Vector2u16 tile, u16 id, bool persistent) {
	if(tile.x + tile.y * m_rect.width < m_rect.width * m_rect.height) {
		m_data[tile.x + tile.y * m_rect.width] = id;
		
		if(persistent) m_baseData[tile.x + tile.y * m_rect.width] = id;
	}
	
	m_renderer.updateTile(tile, id, *this);
}

bool Map::passable(Vector2u16 position) {
	s16 tile = m_tileset.info()[getTile({(u16)position.x / m_tileset.tileWidth(),
	                                     (u16)position.y / m_tileset.tileHeight()})];
	
	return TilesInfos::infos[tile][((s16)position.x & 0xF) / (m_tileset.tileWidth()  / 2)
	                             + ((s16)position.y & 0xF) / (m_tileset.tileHeight() / 2) * 2] != TilesInfos::SubTileType::NonPassable;
}

bool Map::onDoor(Vector2u16 position) {
	s16 tile = m_tileset.info()[getTile({position.x / m_tileset.tileWidth(),
	                                     position.y / m_tileset.tileHeight()})];
	
	return TilesInfos::infos[tile][((s16)position.x & 0xF) / (m_tileset.tileWidth()  / 2)
	                             + ((s16)position.y & 0xF) / (m_tileset.tileHeight() / 2) * 2] == TilesInfos::SubTileType::ChangeMap;
}

bool Map::isTile(Vector2u16 position, u16 tile) {
	return m_tileset.info()[getTile({(u16)position.x / m_tileset.tileWidth(),
	                                 (u16)position.y / m_tileset.tileHeight()})] == tile;
}

Map &Map::getMap(u16 area, Vector2u16 map) {
	return ResourceHandler::getInstance().get<Map>(MapLoader::makeName(area, map));
}

bool Map::mapExists(u16 area, Vector2u16 map) {
	return ResourceHandler::getInstance().has(MapLoader::makeName(area, map));
}

