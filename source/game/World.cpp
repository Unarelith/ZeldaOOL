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
#include "PlayerFactory.hpp"
#include "World.hpp"

World *World::s_instance = nullptr;

World::World() {
	m_currentMap = &Map::getMap(0, 0, 0);

	m_player = PlayerFactory::create(64, 48);
}

void World::update() {
	m_currentMap->update();
}

void World::draw(RenderTarget &target, RenderStates states) const {
	applyTransform(states);

	if (m_currentMap)
		target.draw(*m_currentMap, states);
}

