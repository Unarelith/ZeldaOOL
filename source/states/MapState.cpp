/*
 * =====================================================================================
 *
 *       Filename:  MapState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/09/2014 21:08:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "MapState.hpp"

MapState::MapState() {
	m_stats.load("graphics/interface/stats.png");
	
	m_tileset.load("graphics/tilesets/plain.png");
	
	m_map.load("data/maps/a1.tmx", m_tileset);
}

MapState::~MapState() {
}

void MapState::update() {
	
}

void MapState::render() {
	m_map.draw();
	
	m_stats.draw(0, 0);
}

