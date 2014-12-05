/*
 * =====================================================================================
 *
 *       Filename:  ScrollingTransition.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2014 05:30:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ScrollingTransition.hpp"

ScrollingTransition::ScrollingTransition(u8 mode) : m_statsBar(StatsBar::getInstance()) {
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
	
	//m_nextMap = ResourceHandler::getInstance().get<Map>();
	m_nextMap = nullptr;
	
	//m_nextMap->resetTiles();
	//m_nextMap->updateTiles();
	//m_nextMap->setPosition(GameState::getInstance().currentMap().width() * 16 * vx,
	//						 GameState::getInstance().currentMap().height() * 16 * vy);
	
	m_scrolled = 0;
}

ScrollingTransition::~ScrollingTransition() {
}

void ScrollingTransition::update() {
	
}

void ScrollingTransition::draw() {
	
}

