/*
 * =====================================================================================
 *
 *       Filename:  TeleporterLoader.cpp
 *
 *    Description:
 *
 *        Created:  22/02/2015 16:08:35
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Direction.hpp"
#include "TeleporterComponent.hpp"
#include "TeleporterFactory.hpp"
#include "TeleporterLoader.hpp"

void TeleporterLoader::load(XMLElement *teleporterElement, SceneObjectList &objectList) {
	float tileX = teleporterElement->FloatAttribute("tileX");
	float tileY = teleporterElement->FloatAttribute("tileY");

	XMLElement *destinationElement = teleporterElement->FirstChildElement("destination");

	u16 area = destinationElement->IntAttribute("area");

	u16 mapX = destinationElement->IntAttribute("mapX");
	u16 mapY = destinationElement->IntAttribute("mapY");

	XMLElement *playerElement = teleporterElement->FirstChildElement("player");

	u16 playerX = playerElement->FloatAttribute("tileX") * 16;
	u16 playerY = playerElement->FloatAttribute("tileY") * 16;

	Direction playerDirection = Direction::None;
	if(playerElement->Attribute("direction", "left")) {
		playerDirection = Direction::Left;
	}
	else if(playerElement->Attribute("direction", "right")) {
		playerDirection = Direction::Right;
	}
	else if(playerElement->Attribute("direction", "up")) {
		playerDirection = Direction::Up;
	}
	else if(playerElement->Attribute("direction", "down")) {
		playerDirection = Direction::Down;
	}

	SceneObject &teleporter = objectList.addObject(TeleporterFactory::create(tileX, tileY));

	auto &teleporterComponent = teleporter.get<TeleporterComponent>();
	teleporterComponent.setDestination(area, mapX, mapY, playerX, playerY, playerDirection);
}

