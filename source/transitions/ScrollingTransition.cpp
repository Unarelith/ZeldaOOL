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
#include "Application.hpp"
#include "CharacterManager.hpp"
#include "Config.hpp"
#include "Map.hpp"
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
	
	m_nextMap = &Map::getMap(Map::currentMap->area(),
	                                Map::currentMap->x() + m_vx,
	                                Map::currentMap->y() + m_vy);
	
	m_nextMap->resetTiles();
	m_nextMap->updateTiles();
	
	m_nextMap->view().setPosition(Map::currentMap->width() * 16 * m_vx,
	                              Map::currentMap->height() * 16 * m_vy + 16);
	
	m_scrolled = 0;
	
	Sprite::pause = true;
}

ScrollingTransition::~ScrollingTransition() {
}

void ScrollingTransition::update() {
	CharacterManager::player.move(m_vx * 0.15f, m_vy * 0.21f);
	
	Map::currentMap->view().move(-m_vx * 1.6f, -m_vy * 1.5f);
	m_nextMap->view().move(-m_vx * 1.6f, -m_vy * 1.5f);
	
	if(m_vx != 0) m_scrolled += 1.6f;
	if(m_vy != 0) m_scrolled += 1.5f;
	
	if((m_scrolled >= WINDOW_WIDTH		 && m_vx != 0)
	|| (m_scrolled >= WINDOW_HEIGHT - 16 && m_vy != 0)) {
		if(m_vx < 0)      CharacterManager::player.move(m_nextMap->width() * 16, 0);
		else if(m_vx > 0) CharacterManager::player.move(-Map::currentMap->width() * 16, 0);
		else if(m_vy < 0) CharacterManager::player.move(0, m_nextMap->height() * 16);
		else if(m_vy > 0) CharacterManager::player.move(0, -Map::currentMap->height() * 16);
		
		Map::currentMap = m_nextMap;
		Map::currentMap->view().setPosition(0, 16);
		
		m_scrolled = 0;
		
		Sprite::pause = false;
		
		m_atEnd = true;
	}
}

void ScrollingTransition::draw() {
	View::bind(&m_nextMap->view());
	
	m_nextMap->draw();
	
	View::bind(&Map::currentMap->view());
	
	Map::currentMap->draw();
	
	AnimationManager::playAnimations();
	
	CharacterManager::player.draw();
	
	View::bind(nullptr);
	
	m_statsBar.draw();
}

