/*
 * =====================================================================================
 *
 *       Filename:  ScrollingTransition.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 10:29:53
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationWindow.hpp"
#include "Map.hpp"
#include "ScrollingTransition.hpp"
#include "Sprite.hpp"

ScrollingTransition::ScrollingTransition(u8 mode) {
	m_mode = (Mode)mode;
	
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
	
	Sprite::pause = true;
}

void ScrollingTransition::update() {
	Map::currentMap->view().move(-m_vx * 1.6f, -m_vy * 1.5f);
	m_nextMap->view().move(-m_vx * 1.6f, -m_vy * 1.5f);
	
	if(m_vx != 0) m_scrolled += 1.6f;
	if(m_vy != 0) m_scrolled += 1.5f;
	
	if((m_scrolled >= ApplicationWindow::screenWidth       && m_vx != 0)
	|| (m_scrolled >= ApplicationWindow::screenHeight - 16 && m_vy != 0)) {
		Map::currentMap = m_nextMap;
		Map::currentMap->view().setPosition(0, 16);
		
		m_scrolled = 0;
		
		Sprite::pause = false;
		
		m_atEnd = true;
	}
}

void ScrollingTransition::draw() {
	m_nextMap->draw();
}

