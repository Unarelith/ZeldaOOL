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
#include "GameState.hpp"
#include "MapState.hpp"

MapState::MapState() : m_statsBar(StatsBar::getInstance()) {
	m_link = &Player::getInstance();
	
	m_map = &GameState::getInstance().currentMap();
}

MapState::~MapState() {
}

void MapState::update() {
	m_map->update();
	
	m_link->move();
}

void MapState::draw() {
	m_map->draw();
	
	m_statsBar.draw();
	
	Application::getInstance().window().setView(TileMap::view);
	
	m_link->draw();
	
	Application::getInstance().resetView();
}

