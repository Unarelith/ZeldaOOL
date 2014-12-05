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
#include "Application.hpp"
#include "Config.hpp"
#include "GameState.hpp"
#include "Player.hpp"
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
	
	m_nextMap = &GameState::getInstance().getMap(0, 1);
	//m_nextMap = nullptr;
	
	//m_nextMap->resetTiles();
	//m_nextMap->updateTiles();
	m_nextMap->setPosition(GameState::getInstance().currentMap().width() * 16 * m_vx,
						   GameState::getInstance().currentMap().height() * 16 * m_vy);
	
	m_scrolled = 0;
	
	Sprite::pause = true;
}

ScrollingTransition::~ScrollingTransition() {
}

void ScrollingTransition::update() {
	Player::getInstance().move(m_vx * 0.15f, m_vy * 0.21f);
	
	TileMap::view.move(m_vx * 1.6f, m_vy * 1.5f);
	
	if(m_vx != 0) m_scrolled += 1.6f;
	if(m_vy != 0) m_scrolled += 1.5f;
	
	if((m_scrolled >= SCREEN_WIDTH		 && m_vx != 0)
	|| (m_scrolled >= SCREEN_HEIGHT - 16 && m_vy != 0)) {
		if(m_vx < 0) {
			Player::getInstance().move(m_nextMap->width() * 16, 0);
		}
		else if(m_vx > 0) {
			Player::getInstance().move(-GameState::getInstance().currentMap().width() * 16, 0);
		}
		else if(m_vy < 0) {
			Player::getInstance().move(0, m_nextMap->height() * 16);
		}
		else if(m_vy > 0) {
			Player::getInstance().move(0, -GameState::getInstance().currentMap().height() * 16);
		}
		
		GameState::getInstance().setCurrentMap(m_nextMap);
		GameState::getInstance().currentMap().setPosition(0, 0);
		TileMap::view.setCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 16);
		
		m_scrolled = 0;
		
		Sprite::pause = false;
		
		m_atEnd = true;
	}
}

void ScrollingTransition::draw() {
	GameState::getInstance().currentMap().draw();
	
	m_nextMap->draw();
	
	Application::getInstance().window().setView(TileMap::view);
	
	Player::getInstance().draw();
	
	Application::getInstance().resetView();
	
	m_statsBar.draw();
}

