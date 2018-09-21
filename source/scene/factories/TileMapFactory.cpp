/*
 * =====================================================================================
 *
 *       Filename:  TileMapFactory.cpp
 *
 *    Description:
 *
 *        Created:  10/04/2018 17:04:38
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "CollisionComponent.hpp"
#include "TileMap.hpp"
#include "TileMapFactory.hpp"
#include "ResourceHandler.hpp"

SceneObject TileMapFactory::create(const std::string &mapName) {
	SceneObject object(mapName, "tilemap");
	object.set<CollisionComponent>();

	// FIXME: Hard map copy
	object.set<TileMap>(ResourceHandler::getInstance().get<TileMap>(mapName));

	return object;
}

