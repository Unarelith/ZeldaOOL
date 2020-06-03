/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
// #include <gk/audio/AudioPlayer.hpp> // FIXME: GAMEKIT
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
		// gk::AudioPlayer::playMusic("bgm-plain"); // FIXME: GAMEKIT
	}
	else if(m_nextMap->area() == 1) {
		// gk::AudioPlayer::playMusic("bgm-indoor"); // FIXME: GAMEKIT
	} else {
		// gk::AudioPlayer::playMusic("bgm-underground"); // FIXME: GAMEKIT
	}

	BehaviourController controller;
	controller.reset(World::getInstance().player());

	m_drawStatsBar = false;

	m_rect1.setFillColor(m_color);
	m_rect2.setFillColor(m_color);

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

