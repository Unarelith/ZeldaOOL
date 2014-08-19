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
#include "MapState.hpp"

MapState::MapState(State *parent) : State(parent) {
	MapManager::init();
}

MapState::~MapState() {
}

void MapState::update() {
	m_player.move();
}

void MapState::render() {
	Application::window.draw(*MapManager::currentMap);
	
	m_player.draw();
}

