/*
 * =====================================================================================
 *
 *       Filename:  MapEventManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:36:19
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
#include "MapEventManager.hpp"

u16 MapEventManager::lastPlayerX = 0;
u16 MapEventManager::lastPlayerY = 0;

void MapEventManager::update() {
	u16 tmpPlayerX = (CharacterManager::player.x() + 6) / 16;
	u16 tmpPlayerY = (CharacterManager::player.y() + 11) / 16;
	
	if(lastPlayerX != tmpPlayerX || lastPlayerY != tmpPlayerY) {
		if(CharacterManager::player.onTile(TilesData::TileType::Button)) {
			MapManager::currentMap->sendEvent(Map::EventType::ButtonPressed);
		}
		
		lastPlayerX = tmpPlayerX;
		lastPlayerY = tmpPlayerY;
	}
}

