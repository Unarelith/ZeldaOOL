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
#include "GrassFactory.hpp"
#include "ResourceHandler.hpp"
#include "SceneObjectList.hpp"
#include "TileMap.hpp"
#include "TileMapFactory.hpp"
#include "TilesInfos.hpp"

SceneObject TileMapFactory::create(const std::string &mapName) {
	SceneObject object("tilemap-" + mapName, "tilemap");
	object.set<CollisionComponent>();

	auto &objectList = object.set<SceneObjectList>();
	load(mapName, objectList);

	// FIXME: Hard map copy
	auto &tileMap = object.set<TileMap>(ResourceHandler::getInstance().get<TileMap>("tilemap-" + mapName));
	for(u16 tileY = 0 ; tileY < tileMap.height() ; tileY++) {
		for(u16 tileX = 0 ; tileX < tileMap.width() ; tileX++) {
			u16 tileType = tileMap.getTileInfo(tileX * 16, tileY * 16).type();

			if(tileType == TilesInfos::TileType::GrassTile) {
				objectList.addObject(GrassFactory::create(tileX, tileY));
			}
			else if(tileType == TilesInfos::TileType::LowGrassTile) {
				objectList.addObject(GrassFactory::create(tileX, tileY, true));
			}
		}
	}

	return object;
}

#include "Filesystem.hpp"
#include "XMLFile.hpp"

#include "ButtonLoader.hpp"
#include "ChestLoader.hpp"
#include "NPCLoader.hpp"
#include "OctorokLoader.hpp"
#include "TeleporterLoader.hpp"

void TileMapFactory::load(const std::string &mapName, SceneObjectList &objectList) {
	if(Filesystem::fileExists("resources/config/maps/" + mapName + ".xml")) {
		XMLFile doc("resources/config/maps/" + mapName + ".xml");

		XMLElement *objectElement = doc.FirstChildElement("map").FirstChildElement().ToElement();
		while(objectElement) {
			std::string objectName = objectElement->Name();

			if(objectName == "button") {
				ButtonLoader::load(objectElement, objectList);
			}
			else if(objectName == "chest") {
				ChestLoader::load(objectElement, objectList);
			}
			else if(objectName == "npc") {
				NPCLoader::load(objectElement, objectList);
			}
			else if(objectName == "octorok") {
				OctorokLoader::load(objectElement, objectList);
			}
			else if(objectName == "teleporter") {
				TeleporterLoader::load(objectElement, objectList);
			}

			objectElement = objectElement->NextSiblingElement();
		}
	}
}

