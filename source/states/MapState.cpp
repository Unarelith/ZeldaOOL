/*
 * =====================================================================================
 *
 *       Filename:  MapState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:23:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "MapState.hpp"

MapState::MapState() {
	m_image.load("graphics/characters/link.png");
}

MapState::~MapState() {
}

void MapState::update() {
	
}

void MapState::draw() {
	m_image.draw(20, 20);
}

