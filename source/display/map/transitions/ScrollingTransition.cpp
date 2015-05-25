/*
 * =====================================================================================
 *
 *       Filename:  ScrollingTransition.cpp
 *
 *    Description:  
 *
 *        Created:  05/10/2014 17:45:59
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "Map.hpp"
#include "PositionComponent.hpp"
#include "Scene.hpp"
#include "ScrollingTransition.hpp"
#include "Sprite.hpp"

ScrollingTransition::ScrollingTransition(Mode mode) {
	m_mode = mode;
	
	if(m_mode == Mode::ScrollingLeft) {
		m_v.x = -1;
	}
	else if(m_mode == Mode::ScrollingRight) {
		m_v.x = 1;
	}
	else if(m_mode == Mode::ScrollingUp) {
		m_v.y = -1;
	}
	else if(m_mode == Mode::ScrollingDown) {
		m_v.y = 1;
	}
	
	m_nextMap = &Map::getMap(Map::currentMap->area(),
	                         Map::currentMap->rect().position() + m_v);
	
	m_nextMap->reset();
	m_nextMap->updateTiles();
	
	m_nextMap->view().setPosition(Map::currentMap->rect().width * 16 * m_v.x,
	                              Map::currentMap->rect().height * 16 * m_v.y + 16);
	
	Sprite::pause = true;
}

void ScrollingTransition::update() {
	PositionComponent *positionComponent = nullptr;
	
	if(Scene::player) {
		positionComponent = &Scene::player->get<PositionComponent>();
		positionComponent->move({m_v.x * 0.15f, m_v.y * 0.21f});
	}
	
	Map::currentMap->view().move(-m_v.x * 1.6f, -m_v.y * 1.5f);
	m_nextMap->view().move(-m_v.x * 1.6f, -m_v.y * 1.5f);
	
	if(m_v.x != 0) m_scrolled += 1.6f;
	if(m_v.y != 0) m_scrolled += 1.5f;
	
	if((m_scrolled >= Application::screenWidth       && m_v.x != 0)
	|| (m_scrolled >= Application::screenHeight - 16 && m_v.y != 0)) {
		if(positionComponent) {
			if(m_v.x < 0)      positionComponent->move({(float)(m_nextMap->rect().width * 16), 0.0f});
			else if(m_v.x > 0) positionComponent->move({(float)(-Map::currentMap->rect().width * 16), 0.0f});
			else if(m_v.y < 0) positionComponent->move({0.0f, (float)(m_nextMap->rect().height * 16)});
			else if(m_v.y > 0) positionComponent->move({0.0f, (float)(-Map::currentMap->rect().height * 16)});
		}
		
		Map::currentMap = m_nextMap;
		Map::currentMap->view().setPosition(0, 16);
		
		m_scrolled = 0;
		
		Sprite::pause = false;
		
		m_atEnd = true;
	}
	
	if(Scene::player && positionComponent) {
		auto &objectList = Scene::player->get<SceneObjectList>();
		for(auto &object : objectList) {
			auto &position = object.get<PositionComponent>();
			position.x = positionComponent->x;
			position.y = positionComponent->y;
		}
	}
}

void ScrollingTransition::draw() {
	m_nextMap->draw();
	
	Map::currentMap->draw();
}

