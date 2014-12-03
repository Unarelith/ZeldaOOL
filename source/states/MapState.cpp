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
#include "ResourceHandler.hpp"

MapState::MapState() {
	m_link.load("link", 16, 16);
	
	m_map = &ResourceHandler::getInstance().get<TileMap>("a1");
	m_map->setPosition(0, 16);
}

MapState::~MapState() {
}

void MapState::update() {
}

void MapState::draw() {
	m_map->draw();
	
	m_link.drawFrame(80, 64, 0);
}

