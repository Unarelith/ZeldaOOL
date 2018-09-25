/*
 * =====================================================================================
 *
 *       Filename:  ScrollingTransition.cpp
 *
 *    Description:
 *
 *        Created:  05/10/2014 17:45:59
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "Config.hpp"
#include "PositionComponent.hpp"
#include "Scene.hpp"
#include "ScrollingTransition.hpp"
#include "Sprite.hpp"
#include "World.hpp"

ScrollingTransition::ScrollingTransition(Mode mode) {
	m_mode = mode;

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

	m_nextMap = &World::getInstance().getSideMap(m_vx, m_vy);
	m_nextMap->reset();
	m_nextMap->updateTiles();
	m_nextMap->setPosition(m_nextMap->width() * 16 * m_vx,
	                       m_nextMap->height() * 16 * m_vy + 16);

	Sprite::pause = true;
}

void ScrollingTransition::update() {
	PositionComponent &positionComponent = World::getInstance().player().get<PositionComponent>();
	positionComponent.move(m_vx * 0.15f, m_vy * 0.21f);

	World::getInstance().currentMap()->move(-m_vx * 1.6f, -m_vy * 1.5f);
	m_nextMap->move(-m_vx * 1.6f, -m_vy * 1.5f);

	if(m_vx != 0) m_scrolled += 1.6f;
	if(m_vy != 0) m_scrolled += 1.5f;

	if((m_scrolled >= SCREEN_WIDTH       && m_vx != 0)
	|| (m_scrolled >= SCREEN_HEIGHT - 16 && m_vy != 0)) {
		if(m_vx < 0)      positionComponent.move(m_nextMap->width() * 16, 0);
		else if(m_vx > 0) positionComponent.move(-World::getInstance().currentMap()->width() * 16, 0);
		else if(m_vy < 0) positionComponent.move(0, m_nextMap->height() * 16);
		else if(m_vy > 0) positionComponent.move(0, -World::getInstance().currentMap()->height() * 16);

		World::getInstance().setCurrentMap(m_nextMap);
		World::getInstance().currentMap()->setPosition(0, 16);

		m_scrolled = 0;

		Sprite::pause = false;

		m_atEnd = true;
	}

	auto &objectList = World::getInstance().player().get<SceneObjectList>();
	for(auto &object : objectList) {
		if (object.has<PositionComponent>()) {
			auto &position = object.get<PositionComponent>();
			position.x = positionComponent.x;
			position.y = positionComponent.y;
		}
	}
}

void ScrollingTransition::draw(RenderTarget &target, RenderStates states) const {
	target.draw(*m_nextMap, states);

	target.draw(*World::getInstance().currentMap(), states);
}

