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

GameState::GameState() {
	m_currentMap = &Map::getMap(0, 0, 0);
	m_currentMap->updateTiles();
	
	m_playerRupees = 197;
}

GameState::~GameState() {
}

