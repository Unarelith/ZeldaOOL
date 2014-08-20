/*
 * =====================================================================================
 *
 *       Filename:  MapState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 14:00:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "Application.hpp"
#include "MapManager.hpp"
#include "CharacterManager.hpp"
#include "MapState.hpp"

MapState::MapState(State *parent) : State(parent) {
	MapManager::init();
}

MapState::~MapState() {
}

void MapState::update() {
	CharacterManager::player.move();
}

void MapState::render() {
	m_statsBar.draw();
	
	Application::window.draw(*MapManager::currentMap);
	
	CharacterManager::player.draw();
}

