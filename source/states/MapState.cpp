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
#include "Sound.hpp"
#include "TimeManager.hpp"
#include "Application.hpp"
#include "CharacterManager.hpp"
#include "EffectManager.hpp"
#include "AnimationManager.hpp"
#include "MapEventManager.hpp"
#include "MapState.hpp"

MapState::MapState(State *parent) : State(parent) {
	m_mode = Mode::Normal;
	
	m_mapView.reset(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	
	m_nextMap = nullptr;
	m_scrolled = 0;
	
	MapManager::init();
	
	EffectManager::init();
	
	AnimationManager::init();
	
	Object button(7, 2);
	
	button.setEventAction(Map::EventType::ButtonPressed, [&](Object *obj) {
		Sound::Effect::chest.play();
		
		MapManager::currentMap->setTile(obj->x() / 16, obj->y() / 16 - 1, 8);
		
		MapManager::currentMap->setTile(7, 7, 36);
		MapManager::currentMap->setTile(8, 7, 36);
	});
	
	MapManager::currentMap->addObject(button);
	
	Sound::Music::plain.play();
}

MapState::~MapState() {
}

void MapState::scrollMaps(double vx, double vy) {
	if(!m_nextMap) {
		m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() + vx + (MapManager::currentMap->y() + vy) * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
		
		m_nextMap->update();
		m_nextMap->setPosition(MapManager::currentMap->width() * 16 * vx, MapManager::currentMap->height() * 16 * vy);
		
		Sprite::pause = true;
	}
	
	CharacterManager::player.move(270 * -vx * TimeManager::dt, 235 * -vy * TimeManager::dt);
	m_mapView.move(300 * vx * TimeManager::dt, 280 * vy * TimeManager::dt);
	
	if(vx != 0) m_scrolled += TimeManager::dt * 300.0f;
	if(vy != 0) m_scrolled += TimeManager::dt * 280.0f;
}

void MapState::update() {
	if(m_mode == Mode::Normal) {
		CharacterManager::player.update();
		
		MapEventManager::update();
		
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
		scrollMaps(-1, 0);
	}
	else if(m_mode == Mode::ScrollingRight) {
		scrollMaps(1, 0);
	}
	else if(m_mode == Mode::ScrollingUp) {
		scrollMaps(0, -1);
	}
	else if(m_mode == Mode::ScrollingDown) {
		scrollMaps(0, 1);
	}
	
	if((m_scrolled >= WINDOW_WIDTH && (m_mode == Mode::ScrollingLeft || m_mode == Mode::ScrollingRight))
	|| (m_scrolled >= WINDOW_HEIGHT - 16 && (m_mode == Mode::ScrollingUp || m_mode == Mode::ScrollingDown))) {
		MapManager::currentMap = m_nextMap;
		MapManager::currentMap->setPosition(0, 0);
		
		m_nextMap = nullptr;
		m_scrolled = 0;
		
		Sprite::pause = false;
		
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
	
	AnimationManager::playAnimations();
	
	Application::window.setView(Application::window.getDefaultView());
	
	CharacterManager::player.draw();
	
	m_statsBar.draw();
}

