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
#include <cmath>

#include "Debug.hpp"
#include "Application.hpp"
#include "CharacterManager.hpp"
#include "MapState.hpp"

MapState::MapState(State *parent) : State(parent) {
	m_mode = Mode::Normal;
	
	m_mapView.reset(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	
	m_nextMap = nullptr;
	m_scrolled = 0;
	
	MapManager::init();
}

MapState::~MapState() {
}

void MapState::update() {
	if(m_mode == Mode::Normal) {
		CharacterManager::player.move();
		
		if(CharacterManager::player.y() < 12) {
			m_mode = Mode::ScrollingUp;
		}
		else if(CharacterManager::player.y() + 16 > WINDOW_HEIGHT) {
			m_mode = Mode::ScrollingDown;
		}
	}
	
	if(m_mode == Mode::ScrollingLeft) {
		if(!m_nextMap) {
			m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() - 1 + MapManager::currentMap->y() * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
			
			m_nextMap->update(-MapManager::currentMap->width(), 0);
		}
		
		MapManager::currentMap->move(8, 0);
		m_scrolled++;
	}
	else if(m_mode == Mode::ScrollingRight) {
		if(!m_nextMap) {
			m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() + 1 + MapManager::currentMap->y() * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
			
			m_nextMap->update(MapManager::currentMap->width(), 0);
		}
		
		MapManager::currentMap->move(-8, 0);
		m_scrolled++;
	}
	else if(m_mode == Mode::ScrollingUp) {
		if(!m_nextMap) {
			m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() + (MapManager::currentMap->y() - 1) * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
			
			m_nextMap->update();
			m_nextMap->setPosition(0, -MapManager::currentMap->height() * 16);
		}
		
		CharacterManager::player.move(0, 4.4);
		m_mapView.move(0, -5);
		m_scrolled++;
	}
	else if(m_mode == Mode::ScrollingDown) {
		if(!m_nextMap) {
			m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() + (MapManager::currentMap->y() + 1) * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
			
			m_nextMap->update();
			m_nextMap->setPosition(0, MapManager::currentMap->height() * 16);
		}
		
		CharacterManager::player.move(0, -4.3);
		m_mapView.move(0, 5);
		m_scrolled++;
	}
	
	if((m_scrolled >= WINDOW_WIDTH / 5 - 2.5
	 && (m_mode == Mode::ScrollingLeft || m_mode == Mode::ScrollingRight))
	|| (m_scrolled >= WINDOW_HEIGHT / 5 - 2.5
	 && (m_mode == Mode::ScrollingUp || m_mode == Mode::ScrollingDown))) {
		MapManager::currentMap = m_nextMap;
		MapManager::currentMap->setPosition(0, 0);
		
		m_nextMap = nullptr;
		m_scrolled = 0;
		
		if(m_mode == Mode::ScrollingUp) {
			CharacterManager::player.setPosition(CharacterManager::player.x(), CharacterManager::player.y() + m_scrolled * 4.4);
		}
		else if(m_mode == Mode::ScrollingDown) {
			CharacterManager::player.setPosition(CharacterManager::player.x(), CharacterManager::player.y() - m_scrolled * 4.3);
		}
		
		m_mapView.reset(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
		
		m_mode = Mode::Normal;
	}
}

void MapState::render() {
	Application::window.setView(m_mapView);
	
	if(m_mode == Mode::Normal) {
		MapManager::currentMap->draw();
	}
	
	if(m_mode == Mode::ScrollingLeft
	|| m_mode == Mode::ScrollingRight
	|| m_mode == Mode::ScrollingUp
	|| m_mode == Mode::ScrollingDown) {
		MapManager::currentMap->draw();
		
		if(m_nextMap) m_nextMap->draw();
	}
	
	Application::window.setView(Application::window.getDefaultView());
	
	CharacterManager::player.draw();
	
	m_statsBar.draw();
}

