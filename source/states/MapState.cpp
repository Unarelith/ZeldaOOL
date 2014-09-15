/*
 * =====================================================================================
 *
 *       Filename:  MapState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:22:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "MapState.hpp"

MapState::MapState() {
	m_test.load("graphics/interface/stats.png");
}

MapState::~MapState() {
}

void MapState::update() {
	
}

void MapState::render() {
	m_test.draw(0, 0);
}

