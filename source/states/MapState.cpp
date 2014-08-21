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
		
		if(CharacterManager::player.x() < -3) {
			m_mode = Mode::ScrollingLeft;
		}
		else if(CharacterManager::player.x() + 13 > MapManager::currentMap->width() * 16) {
			m_mode = Mode::ScrollingRight;
		}
		else if(CharacterManager::player.y() < 15) {
			m_mode = Mode::ScrollingUp;
		}
		else if(CharacterManager::player.y() + 15 > MapManager::currentMap->height() * 16 + 16) {
			m_mode = Mode::ScrollingDown;
		}
	}
	
	if(m_mode == Mode::ScrollingLeft) {
		if(!m_nextMap) {
			m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() - 1 + MapManager::currentMap->y() * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
			
			m_nextMap->update();
			m_nextMap->setPosition(-MapManager::currentMap->width() * 16, 0);
			
			Sprite::pause = true;
		}
		
		CharacterManager::player.move(4.6, 0);
		m_mapView.move(-5, 0);
		m_scrolled++;
	}
	else if(m_mode == Mode::ScrollingRight) {
		if(!m_nextMap) {
			m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() + 1 + MapManager::currentMap->y() * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
			
			m_nextMap->update();
			m_nextMap->setPosition(MapManager::currentMap->width() * 16, 0);
			
			Sprite::pause = true;
		}
		
		CharacterManager::player.move(-4.6, 0);
		m_mapView.move(5, 0);
		m_scrolled++;
	}
	else if(m_mode == Mode::ScrollingUp) {
		if(!m_nextMap) {
			m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() + (MapManager::currentMap->y() - 1) * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
			
			m_nextMap->update();
			m_nextMap->setPosition(0, -MapManager::currentMap->height() * 16);
			
			Sprite::pause = true;
		}
		
		CharacterManager::player.move(0, 4.3);
		m_mapView.move(0, -5);
		m_scrolled++;
	}
	else if(m_mode == Mode::ScrollingDown) {
		if(!m_nextMap) {
			m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() + (MapManager::currentMap->y() + 1) * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
			
			m_nextMap->update();
			m_nextMap->setPosition(0, MapManager::currentMap->height() * 16);
			
			Sprite::pause = true;
		}
		
		CharacterManager::player.move(0, -4.3);
		m_mapView.move(0, 5);
		m_scrolled++;
	}
	
	if((m_scrolled >= WINDOW_WIDTH / 5
	 && (m_mode == Mode::ScrollingLeft || m_mode == Mode::ScrollingRight))
	|| (m_scrolled >= WINDOW_HEIGHT / 5 - 2.5
	 && (m_mode == Mode::ScrollingUp || m_mode == Mode::ScrollingDown))) {
		MapManager::currentMap = m_nextMap;
		MapManager::currentMap->setPosition(0, 0);
		
		m_nextMap = nullptr;
		m_scrolled = 0;
		
		Sprite::pause = false;
		
		if(m_mode == Mode::ScrollingLeft) {
			CharacterManager::player.setPosition(CharacterManager::player.x() + m_scrolled * 4.6, CharacterManager::player.y());
		}
		else if(m_mode == Mode::ScrollingRight) {
			CharacterManager::player.setPosition(CharacterManager::player.x() - m_scrolled * 4.6, CharacterManager::player.y());
		}
		else if(m_mode == Mode::ScrollingUp) {
			CharacterManager::player.setPosition(CharacterManager::player.x(), CharacterManager::player.y() + m_scrolled * 4.3);
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
	
	MapManager::currentMap->draw();
	
	if(m_mode == Mode::ScrollingLeft
	|| m_mode == Mode::ScrollingRight
	|| m_mode == Mode::ScrollingUp
	|| m_mode == Mode::ScrollingDown) {
		if(m_nextMap) m_nextMap->draw();
	}
	
	Application::window.setView(Application::window.getDefaultView());
	
	CharacterManager::player.draw();
	
	m_statsBar.draw();
}

