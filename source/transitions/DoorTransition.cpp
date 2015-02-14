/*
 * =====================================================================================
 *
 *       Filename:  DoorTransition.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 11:09:02
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationWindow.hpp"
#include "DoorTransition.hpp"
#include "Map.hpp"
#include "Sprite.hpp"

DoorTransition::DoorTransition(u16 area, u16 mapX, u16 mapY, u16 playerX, u16 playerY, u8 playerDirection, bool movePlayer) {
	m_nextMap = &Map::getMap(area, mapX, mapY);
	m_nextMap->resetTiles();
	m_nextMap->updateTiles();
	
	m_playerX = playerX;
	m_playerY = playerY;
	
	m_playerDirection = playerDirection;
	
	m_movePlayer = movePlayer;
	
	m_timer.start();
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	m_rect1.resize(ApplicationWindow::screenWidth / 2, ApplicationWindow::screenHeight - 16);
	m_rect2.resize(ApplicationWindow::screenWidth / 2, ApplicationWindow::screenHeight - 16);
	
	m_rect1.setPosition(0, 16);
	m_rect2.setPosition(ApplicationWindow::screenWidth / 2, 16);
	
	//Player::player.setNextState<StandingState>();
	
	Sprite::pause = true;
}

void DoorTransition::update() {
	if(m_timer.time() > 250) {
		glClearColor(Color::text.r / 255.0f, Color::text.g / 255.0f, Color::text.b / 255.0f, 1.0f);
		
		//Player::player.setPosition(m_playerX, m_playerY);
		//Player::player.setDirection(m_playerDirection);
		
		m_rect1.move(-1.5, 0);
		m_rect2.move(1.5, 0);
	}
	
	if(m_rect1.x() + m_rect1.width() < 0) {
		Map::currentMap = m_nextMap;
		
		m_atEnd = true;
		
		Sprite::pause = false;
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}
}

void DoorTransition::draw() {
	if(m_timer.time() > 250) {
		m_nextMap->draw();
		
		//View::bind(&Map::currentMap->view());
		
		//Player::player.draw();
		
		//View::bind(nullptr);
		
		m_rect1.draw(Color::text);
		m_rect2.draw(Color::text);
	}
}

