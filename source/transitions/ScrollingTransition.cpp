/*
 * =====================================================================================
 *
 *       Filename:  ScrollingTransition.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2014 17:45:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "AnimationManager.hpp"
#include "CharacterManager.hpp"
#include "Config.hpp"
#include "MapManager.hpp"
#include "ScrollingTransition.hpp"

ScrollingTransition::ScrollingTransition(u8 mode) {
	m_mode = (Mode)mode;
	
	m_vx = 0;
	m_vy = 0;
	
	if(m_mode == Mode::ScrollingLeft) {
		m_vx = -1;
	}
	else if(m_mode == Mode::ScrollingRight) {
		m_vx = 1;
	}
	else if(m_mode == Mode::ScrollingUp) {
		m_vy = -1;
	}
	else if(m_mode == Mode::ScrollingDown) {
		m_vy = 1;
	}
	
	m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() + m_vx + (MapManager::currentMap->y() + m_vy) * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
	
	m_nextMap->resetTiles();
	m_nextMap->updateTiles();
	m_nextMap->view()->setPosition(MapManager::currentMap->width() * 16 * m_vx, MapManager::currentMap->height() * 16 * m_vy);
	
	m_scrolled = 0;
	
	Sprite::pause = true;
}

ScrollingTransition::~ScrollingTransition() {
}

void ScrollingTransition::update() {
	CharacterManager::player.currentState()->move(-m_vx * 1.45f, -m_vy * 1.275f);
	
	MapManager::currentMap->view()->move(-m_vx * 1.6f, -m_vy * 1.5f);
	m_nextMap->view()->move(-m_vx * 1.6f, -m_vy * 1.5f);
	
	if(m_vx != 0) m_scrolled += 1.6f;
	if(m_vy != 0) m_scrolled += 1.5f;
	
	if((m_scrolled >= WINDOW_WIDTH && (m_mode == Mode::ScrollingLeft || m_mode == Mode::ScrollingRight))
	|| (m_scrolled >= WINDOW_HEIGHT - 16 && (m_mode == Mode::ScrollingUp || m_mode == Mode::ScrollingDown))) {
		MapManager::currentMap = m_nextMap;
		MapManager::currentMap->view()->setPosition(0, 0);
		
		m_nextMap = nullptr;
		m_scrolled = 0;
		
		Sprite::pause = false;
		
		m_atEnd = true;
	}
}

void ScrollingTransition::draw() {
	MapManager::currentMap->draw();
	
	if(m_nextMap) m_nextMap->draw();
	
	AnimationManager::playAnimations();
	
	CharacterManager::player.draw();
	
	m_statsBar.draw();
}

