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
#include <gk/resource/ResourceHandler.hpp>

#include "MapLoader.hpp"
#include "PlayerFactory.hpp"
#include "World.hpp"

World *World::s_instance = nullptr;

World::World() {
	m_currentMap = &getMap(0, 0, 0);

	m_player = PlayerFactory::create(64, 48);
}

void World::update() {
	m_currentMap->scene().update(m_player);
	m_currentMap->update();
}

void World::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	states.transform *= getTransform();

	if (m_currentMap) {
		target.draw(*m_currentMap, states);

		Map *currentMap = World::getInstance().currentMap();
		states.transform.translate(currentMap->getPosition());
		currentMap->scene().draw(World::getInstance().player(), target, states);
	}
}

Map &World::getSideMap(s8 dx, s8 dy) {
	return getMap(m_currentMap->area(), m_currentMap->x() + dx, m_currentMap->y() + dy);
}

Map &World::getMap(u16 area, u16 mapX, u16 mapY) {
	return gk::ResourceHandler::getInstance().get<Map>(MapLoader::makeName(area, mapX, mapY));
}

bool World::mapExists(u16 area, u16 mapX, u16 mapY) {
	return gk::ResourceHandler::getInstance().has(MapLoader::makeName(area, mapX, mapY));
}

