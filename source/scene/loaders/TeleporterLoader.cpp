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

void TeleporterLoader::load(XMLElement *teleporterElement, Scene &scene) {
	Vector2f tile = {teleporterElement->FloatAttribute("tileX"),
	                 teleporterElement->FloatAttribute("tileY")};
	
	XMLElement *destinationElement = teleporterElement->FirstChildElement("destination");
	
	u16 area = destinationElement->IntAttribute("area");
	
	Vector2u16 map = {(u16)destinationElement->IntAttribute("mapX"),
	                  (u16)destinationElement->IntAttribute("mapY")};
	
	XMLElement *playerElement = teleporterElement->FirstChildElement("player");
	
	Vector2f playerPosition = {playerElement->FloatAttribute("tileX") * 16,
	                           playerElement->FloatAttribute("tileY") * 16};
	
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
	
	SceneObject &teleporter = scene.addObject(TeleporterFactory::create(tile));
	
	auto &teleporterComponent = teleporter.get<TeleporterComponent>();
	teleporterComponent.setDestination(area, map, playerPosition, playerDirection);
}

