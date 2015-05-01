/*
 * =====================================================================================
 *
 *       Filename:  DoorLoader.cpp
 *
 *    Description:  
 *
 *        Created:  19/01/2015 21:40:42
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "DoorLoader.hpp"
#include "DoorObject.hpp"
#include "Map.hpp"
#include "Movable.hpp"
#include "XMLFile.hpp"

void DoorLoader::load(const std::string &xmlFilename, ResourceHandler &) {
	XMLFile doc(xmlFilename);
	
	XMLElement *doorElement = doc.FirstChildElement("doors").FirstChildElement("door").ToElement();
	while(doorElement) {
		u16 x = doorElement->FloatAttribute("tileX") * 16;
		u16 y = doorElement->FloatAttribute("tileY") * 16;
		
		u8 direction = 0;
		if(doorElement->FirstChildElement("player")->Attribute("direction", "up")) {
			direction = Movable::Direction::Up;
		}
		else if(doorElement->FirstChildElement("player")->Attribute("direction", "down")) {
			direction = Movable::Direction::Down;
		}
		else if(doorElement->FirstChildElement("player")->Attribute("direction", "left")) {
			direction = Movable::Direction::Left;
		}
		else if(doorElement->FirstChildElement("player")->Attribute("direction", "right")) {
			direction = Movable::Direction::Right;
		}
		
		Map &map = Map::getMap(doorElement->IntAttribute("area"),
		                       doorElement->IntAttribute("mapX"),
		                       doorElement->IntAttribute("mapY"));
		
		DoorObject &door = map.scene().addObject<DoorObject>(x, y);
		door.setDestination(doorElement->FirstChildElement("destination")->IntAttribute("area"),
		                    doorElement->FirstChildElement("destination")->IntAttribute("mapX"),
		                    doorElement->FirstChildElement("destination")->IntAttribute("mapY"),
		                    doorElement->FirstChildElement("player")->FloatAttribute("tileX") * 16,
		                    doorElement->FirstChildElement("player")->FloatAttribute("tileY") * 16,
		                    direction);
		
		doorElement = doorElement->NextSiblingElement();
	}
}

