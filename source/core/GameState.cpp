/*
 * =====================================================================================
 *
 *       Filename:  GameState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 22:32:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include <cmath>

#include "GameState.hpp"
#include "ResourceHandler.hpp"

GameState::GameState() : m_currentMap(&ResourceHandler::getInstance().get<AnimatedMap>("a1")) {
}

GameState::~GameState() {
}

void GameState::setCurrentMap(u8 mapX, u8 mapY) {
	std::string mapName = std::string(1, 'a' + mapY);
	
	if(mapX > 9) {
		mapName += std::string(1, '0' + log10(mapX) + 1) + std::string(1, '0' + (mapX - 10));
	} else {
		mapName += std::string(1, '0' + mapX);
	}
	
	m_currentMap = &ResourceHandler::getInstance().get<AnimatedMap>(mapName);
}

