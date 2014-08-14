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
#include "MapState.hpp"

MapState::MapState(State *parent) : State(parent) {
	m_tileset.load("graphics/tilesets/plain.png");
	
	if(!m_currentMap.load("data/maps/a1.tmx", m_tileset)) {
		error("Couldn't load test map");
	}
}

MapState::~MapState() {
}

void MapState::update() {
	m_player.move();
}

void MapState::render() {
	Application::window.draw(m_currentMap);
	
	m_player.draw();
}

