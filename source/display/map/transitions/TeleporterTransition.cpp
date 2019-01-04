/*
 * =====================================================================================
 *
 *       Filename:  TeleporterTransition.cpp
 *
 *    Description:
 *
 *        Created:  05/10/2014 21:52:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>
#include <gk/scene/Scene.hpp>

#include "Application.hpp"
#include "BehaviourController.hpp"
#include "Color.hpp"
#include "Config.hpp"
#include "Map.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "TeleporterTransition.hpp"
#include "World.hpp"

TeleporterTransition::TeleporterTransition(u16 area, u16 mapX, u16 mapY, u16 playerX, u16 playerY, Direction playerDirection) {
	m_nextMap = &World::getMap(area, mapX, mapY);
	m_nextMap->reset();
	m_nextMap->updateTiles();

	m_color = Color::Text;

	auto &positionComponent = World::getInstance().player().get<PositionComponent>();
	positionComponent.direction = playerDirection;
	positionComponent.x = playerX;
	positionComponent.y = playerY;

	m_timer.start();

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	m_rect1.setSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 16);
	m_rect2.setSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 16);

	m_rect1.setPosition(0, 16);
	m_rect2.setPosition(SCREEN_WIDTH / 2, 16);

	// FIXME: Each map should have a string member with it's bgm name
	if(m_nextMap->area() == 0) {
		gk::AudioPlayer::playMusic("bgm-plain");
	}
	else if(m_nextMap->area() == 1) {
		gk::AudioPlayer::playMusic("bgm-indoor");
	} else {
		gk::AudioPlayer::playMusic("bgm-underground");
	}

	BehaviourController controller;
	controller.reset(World::getInstance().player());

	m_drawStatsBar = false;

	m_rect1.setColor(m_color);
	m_rect2.setColor(m_color);

	Sprite::pause = true;
}

void TeleporterTransition::update() {
	if(m_rect1.getPosition().x + m_rect1.width() < 0) {
		World::getInstance().setCurrentMap(m_nextMap);

		m_atEnd = true;

		Sprite::pause = false;

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	if(m_timer.time() > 250) {
		glClearColor(m_color.r, m_color.g, m_color.b, m_color.a);

		m_drawStatsBar = true;

		m_rect1.move(-1.5, 0);
		m_rect2.move(1.5, 0);
	}
}

void TeleporterTransition::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	if(m_timer.time() > 250) {
		target.draw(*m_nextMap, states);

		Map *currentMap = World::getInstance().currentMap();
		states.transform.translate(currentMap->getPosition());
		currentMap->scene().draw(World::getInstance().player(), target, states);
		states.transform.translate(-currentMap->getPosition());

		target.draw(m_rect1, states);
		target.draw(m_rect2, states);
	}
}

