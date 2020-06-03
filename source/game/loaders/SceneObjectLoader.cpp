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
#include <gk/core/XMLFile.hpp>
#include <gk/core/Filesystem.hpp>

#include "SceneObjectLoader.hpp"

#include "ButtonLoader.hpp"
#include "ChestLoader.hpp"
#include "NPCLoader.hpp"
#include "OctorokLoader.hpp"
#include "TeleporterLoader.hpp"

void SceneObjectLoader::load(const std::string &mapName, gk::Scene &scene) {
	if(gk::Filesystem::fileExists("resources/config/maps/" + mapName + ".xml")) {
		gk::XMLFile doc("resources/config/maps/" + mapName + ".xml");

		tinyxml2::XMLElement *objectElement = doc.FirstChildElement("map").FirstChildElement().ToElement();
		while(objectElement) {
			std::string objectName = objectElement->Name();

			if(objectName == "button") {
				ButtonLoader::load(objectElement, scene);
			}
			else if(objectName == "chest") {
				ChestLoader::load(objectElement, scene);
			}
			else if(objectName == "npc") {
				NPCLoader::load(objectElement, scene);
			}
			else if(objectName == "octorok") {
				OctorokLoader::load(objectElement, scene);
			}
			else if(objectName == "teleporter") {
				TeleporterLoader::load(objectElement, scene);
			}

			objectElement = objectElement->NextSiblingElement();
		}
	}
}

