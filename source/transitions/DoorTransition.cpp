/*
 * =====================================================================================
 *
 *       Filename:  DoorTransition.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 11:09:02
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationWindow.hpp"
#include "DoorTransition.hpp"
#include "Map.hpp"
#include "PositionComponent.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"

DoorTransition::DoorTransition(u16 area, u16 mapX, u16 mapY, u16 playerX, u16 playerY, Direction playerDirection) {
	m_nextMap = &Map::getMap(area, mapX, mapY);
	m_nextMap->resetTiles();
	m_nextMap->updateTiles();
	
	m_playerX = playerX;
	m_playerY = playerY;
	
	m_playerDirection = playerDirection;
	
	m_timer.start();
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	m_rect1.resize(ApplicationWindow::screenWidth / 2, ApplicationWindow::screenHeight - 16);
	m_rect2.resize(ApplicationWindow::screenWidth / 2, ApplicationWindow::screenHeight - 16);
	
	m_rect1.setPosition(0, 16);
	m_rect2.setPosition(ApplicationWindow::screenWidth / 2, 16);
	
	//Scene::player->setNextState<StandingState>();
	
	Sprite::pause = true;
}

void DoorTransition::update() {
	if(m_timer.time() > 250) {
		glClearColor(Color::text.r / 255.0f, Color::text.g / 255.0f, Color::text.b / 255.0f, 1.0f);
		
		if(Scene::player) {
			auto positionComponent = Scene::player->getComponent<PositionComponent>();
			if(positionComponent) {
				positionComponent->x = m_playerX;
				positionComponent->y = m_playerY;
				
				positionComponent->direction = m_playerDirection;
			}
		}
		
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
		
		m_rect1.draw(Color::text);
		m_rect2.draw(Color::text);
	}
}

