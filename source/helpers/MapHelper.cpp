/*
 * =====================================================================================
 *
 *       Filename:  MapHelper.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:19:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "Player.hpp"
#include "MapHelper.hpp"
#include "Map.hpp"
#include "TilesData.hpp"

bool MapHelper::passable(s16 x, s16 y) {
	u16 tile = Map::currentMap->tileset().info()[Map::currentMap->getTile(x >> 4, y >> 4)];
	if(TilesData::infos[tile][(x & 0xF) / 8 + (y & 0xF) / 8 * 2] == TilesData::SubTileType::NonPassable) {
		return false;
	} else {
		return true;
	}
}

bool MapHelper::onDoor(s16 x, s16 y) {
	u16 tile = Map::currentMap->tileset().info()[Map::currentMap->getTile(x >> 4, y >> 4)];
	if(TilesData::infos[tile][(x & 0xF) / 8 + (y & 0xF) / 8 * 2] == TilesData::SubTileType::ChangeMap) {
		return true;
	} else {
		return false;
	}
}

bool MapHelper::isTile(s16 x, s16 y, u16 tile) {
	return Map::currentMap->tileset().info()[Map::currentMap->getTile(x >> 4, y >> 4)] == tile;
}

