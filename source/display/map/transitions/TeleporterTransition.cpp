/*
 * =====================================================================================
 *
 *       Filename:  TeleporterTransition.cpp
 *
 *    Description:  
 *
 *        Created:  05/10/2014 21:52:55
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "AudioPlayer.hpp"
#include "TeleporterTransition.hpp"
#include "Map.hpp"
#include "PositionComponent.hpp"
#include "Scene.hpp"
#include "Sprite.hpp"

TeleporterTransition::TeleporterTransition(u16 area, Vector2u16 map, Vector2f playerPosition, Direction playerDirection, bool movePlayer) {
	m_nextMap = &Map::getMap(area, map);
	m_nextMap->reset();
	m_nextMap->updateTiles();
	
	m_playerPosition = playerPosition;
	
	m_playerDirection = playerDirection;
	
	m_movePlayer = movePlayer;
	
	m_timer.start();
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	m_rect1.resize(Application::screenWidth / 2, Application::screenHeight - 16);
	m_rect2.resize(Application::screenWidth / 2, Application::screenHeight - 16);
	
	m_rect1.setPosition({0.0f, 16.0f});
	m_rect2.setPosition({Application::screenWidth / 2.0f, 16.0f});
	
	// FIXME: TEMPORARY
	if(m_nextMap->area() == 0) {
		AudioPlayer::playMusic("plain");
	}
	else if(m_nextMap->area() == 1) {
		AudioPlayer::playMusic("indoor");
	} else {
		AudioPlayer::playMusic("underground");
	}
	
	// Player::player.setNextState<StandingState>();
	
	m_drawStatsBar = false;
	
	Sprite::pause = true;
}

void TeleporterTransition::update() {
	if(m_rect1.position().x + m_rect1.width() < 0) {
		Map::currentMap = m_nextMap;
		
		m_atEnd = true;
		
		Sprite::pause = false;
		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}
	
	if(m_timer.time() > 250) {
		glClearColor(Color::text.r / 255.0f, Color::text.g / 255.0f, Color::text.b / 255.0f, 1.0f);
		
		m_drawStatsBar = true;
		
		if(Scene::player && Scene::player->has<PositionComponent>()) {
			auto &positionComponent = Scene::player->get<PositionComponent>();
			
			positionComponent.setPosition(m_playerPosition);
			
			positionComponent.direction = (Direction)m_playerDirection;
		}
		
		m_rect1.move(Vector2f(-1.5, 0));
		m_rect2.move(Vector2f(1.5, 0));
	}
}

void TeleporterTransition::draw() {
	if(m_timer.time() > 250) {
		m_nextMap->draw();
		
		m_rect1.draw(Color::text);
		m_rect2.draw(Color::text);
	}
}

