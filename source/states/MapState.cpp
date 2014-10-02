/*
 * =====================================================================================
 *
 *       Filename:  MapState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:22:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include <cmath>

#include "AnimationManager.hpp"
#include "Application.hpp"
#include "Config.hpp"
#include "CharacterManager.hpp"
#include "DialogState.hpp"
#include "EffectManager.hpp"
#include "GameStateManager.hpp"
#include "Keyboard.hpp"
#include "MapEventManager.hpp"
#include "MapState.hpp"
#include "MenuState.hpp"
#include "Sound.hpp"
#include "TimeManager.hpp"
#include "WeaponManager.hpp"

MapState::MapState() {
	m_mode = Mode::Normal;
	
	m_nextMap = nullptr;
	m_scrolled = 0;
	
	CharacterManager::player.load();
	
	MapManager::init();
	
	EffectManager::init();
	
	AnimationManager::init();
	
	Object button(7, 2);
	
	button.setEventAction(Map::EventType::ButtonPressed, [&](Object *obj) {
		Sound::Effect::chest.play();
		
		MapManager::currentMap->setTile(obj->x() / 16, obj->y() / 16 - 1, 8);
		
		MapManager::currentMap->setTile(7, 6, 36);
		MapManager::currentMap->setTile(8, 6, 36);
	});
	
	MapManager::currentMap->addObject(button);
	
	WeaponManager::init();
	
	Sound::Music::plain.play();
}

MapState::~MapState() {
	WeaponManager::free();
}

void MapState::scrollMaps(float vx, float vy) {
	if(!m_nextMap) {
		m_nextMap = &MapManager::maps[MapManager::currentMap->area()][MapManager::currentMap->x() + vx + (MapManager::currentMap->y() + vy) * sqrt(MapManager::maps[MapManager::currentMap->area()].size())];
		
		m_nextMap->resetTiles();
		m_nextMap->updateTiles();
		m_nextMap->setPosition(MapManager::currentMap->width() * 16 * -vx, MapManager::currentMap->height() * 16 * -vy);
		
		Sprite::pause = true;
	}
	
	CharacterManager::player.currentState()->move(-vx * 1.525f, -vy * 1.275f);
	
	MapManager::currentMap->move(vx * 1.7f, vy * 1.5f);
	m_nextMap->move(vx * 1.7f, vy * 1.5f);
	
	if(vx != 0) m_scrolled += 1.7f;
	if(vy != 0) m_scrolled += 1.5f;
}

void MapState::update() {
	if(m_mode == Mode::Normal) {
		MapManager::currentMap->update();
		
		CharacterManager::player.update();
		
		MapEventManager::update();
		
		if(CharacterManager::player.currentState()->stateType() == PlayerState::StateType::TypeMoving) {
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
		
		m_mode = Mode::Normal;
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::Select)) {
		GameStateManager::push(new DialogState(this));
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::Start)) {
		Sound::Effect::menuOpen.play();
		
		GameStateManager::push(new MenuState());
	}
}

void MapState::render() {
	MapManager::currentMap->draw();
	
	if(m_mode == Mode::ScrollingLeft
	|| m_mode == Mode::ScrollingRight
	|| m_mode == Mode::ScrollingUp
	|| m_mode == Mode::ScrollingDown) {
		if(m_nextMap) m_nextMap->draw();
	}
	
	AnimationManager::playAnimations();
	
	CharacterManager::player.draw();
	
	if(m_mode == Normal) EffectManager::drawEffects(&CharacterManager::player);
	
	m_statsBar.draw();
}

