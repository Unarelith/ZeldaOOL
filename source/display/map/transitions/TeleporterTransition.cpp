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
#include "BehaviourController.hpp"
#include "Config.hpp"
#include "Map.hpp"
#include "PositionComponent.hpp"
#include "Scene.hpp"
#include "SpriteComponent.hpp"
#include "TeleporterTransition.hpp"

TeleporterTransition::TeleporterTransition(u16 area, u16 mapX, u16 mapY, u16 playerX, u16 playerY, Direction playerDirection) {
	m_nextMap = &Map::getMap(area, mapX, mapY);
	m_nextMap->reset();
	m_nextMap->updateTiles();

	if(Scene::player) {
		auto &positionComponent = Scene::player->get<PositionComponent>();

		positionComponent.x = playerX;
		positionComponent.y = playerY;

		positionComponent.direction = playerDirection;
	}

	m_timer.start();

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	m_rect1.setSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 16);
	m_rect2.setSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 16);

	m_rect1.setPosition(0, 16);
	m_rect2.setPosition(SCREEN_WIDTH / 2, 16);

	// FIXME: Each map should have a string member with it's bgm name
	if(m_nextMap->area() == 0) {
		AudioPlayer::playMusic("plain");
	}
	else if(m_nextMap->area() == 1) {
		AudioPlayer::playMusic("indoor");
	} else {
		AudioPlayer::playMusic("underground");
	}

	BehaviourController controller;
	controller.reset(*Scene::player);

	m_drawStatsBar = false;

	m_rect1.setColor(Color::text);
	m_rect2.setColor(Color::text);

	Sprite::pause = true;
}

void TeleporterTransition::update() {
	if(m_rect1.getPosition().x + m_rect1.width() < 0) {
		Map::currentMap = m_nextMap;

		m_atEnd = true;

		Sprite::pause = false;

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	if(m_timer.time() > 250) {
		glClearColor(Color::text.r / 255.0f, Color::text.g / 255.0f, Color::text.b / 255.0f, 1.0f);

		m_drawStatsBar = true;

		m_rect1.move(-1.5, 0);
		m_rect2.move(1.5, 0);
	}
}

void TeleporterTransition::draw(RenderTarget &target, RenderStates states) const {
	if(m_timer.time() > 250) {
		target.draw(*m_nextMap, states);

		target.draw(m_rect1, states);
		target.draw(m_rect2, states);
	}
}

