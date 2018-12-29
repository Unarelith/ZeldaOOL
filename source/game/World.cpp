/*
 * =====================================================================================
 *
 *       Filename:  World.cpp
 *
 *    Description:
 *
 *        Created:  21/09/2018 22:22:49
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
	m_currentMap->update();
}

void World::draw(gk::RenderTarget &target, gk::RenderStates states) const {
	states.transform *= getTransform();

	if (m_currentMap)
		target.draw(*m_currentMap, states);
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

