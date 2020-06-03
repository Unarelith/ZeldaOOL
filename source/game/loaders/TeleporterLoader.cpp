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
#include "Direction.hpp"
#include "TeleporterComponent.hpp"
#include "TeleporterFactory.hpp"
#include "TeleporterLoader.hpp"

void TeleporterLoader::load(tinyxml2::XMLElement *teleporterElement, gk::Scene &scene) {
	float tileX = teleporterElement->FloatAttribute("tileX");
	float tileY = teleporterElement->FloatAttribute("tileY");

	tinyxml2::XMLElement *destinationElement = teleporterElement->FirstChildElement("destination");

	u16 area = destinationElement->IntAttribute("area");

	u16 mapX = destinationElement->IntAttribute("mapX");
	u16 mapY = destinationElement->IntAttribute("mapY");

	tinyxml2::XMLElement *playerElement = teleporterElement->FirstChildElement("player");

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

	gk::SceneObject &teleporter = scene.addObject(TeleporterFactory::create(tileX, tileY));

	auto &teleporterComponent = teleporter.get<TeleporterComponent>();
	teleporterComponent.setDestination(area, mapX, mapY, playerX, playerY, playerDirection);
}

