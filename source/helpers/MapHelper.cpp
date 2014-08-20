/*
 * =====================================================================================
 *
 *       Filename:  MapHelper.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/08/2014 19:51:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "TilesData.hpp"
#include "MapManager.hpp"
#include "CharacterManager.hpp"
#include "MapHelper.hpp"

bool MapHelper::passable(s16 x, s16 y) {
	u16 tile = MapManager::currentMap->tileset().info[MapManager::currentMap->getTile(x >> 4, y >> 4)];
	if(TilesData::infos[tile][(x & 0xF) / 8 + (y & 0xF) / 8 * 2] == 1) {
		return false;
	} else {
		return true;
	}
}

bool MapHelper::onDoor(s16 x, s16 y) {
	u16 tile = MapManager::currentMap->tileset().info[MapManager::currentMap->getTile(x >> 4, y >> 4)];
	if(TilesData::infos[tile][(x & 0xF) / 8 + (y & 0xF) / 8 * 2] == 2) {
		return true;
	} else {
		return false;
	}
}

bool MapHelper::isTile(s16 x, s16 y, u16 tile) {
	return MapManager::currentMap->tileset().info[MapManager::currentMap->getTile(x >> 4, y >> 4)] == tile;
}

void MapHelper::scrollMaps(u8 direction) {
	u8 vx = 0;
	u8 vy = 0;
	
	if(direction == Character::Direction::Left) {
		vx = -1;
	}
	else if(direction == Character::Direction::Right) {
		vx = 1;
	}
	else if(direction == Character::Direction::Up) {
		vy = -1;
	}
	else if(direction == Character::Direction::Down) {
		vy = 1;
	}
	
}

