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
#include <gk/resource/ResourceHandler.hpp>

#include "InventoryComponent.hpp"
#include "ItemLoader.hpp"

void ItemLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *itemElement = doc.FirstChildElement("items").FirstChildElement().ToElement();
	while(itemElement) {
		std::string name = itemElement->Attribute("name");

		if(std::string(itemElement->Name()) == "weapon") {
			unsigned int strength = 0, level = 0;

			itemElement->QueryUnsignedAttribute("strength", &strength);
			itemElement->QueryUnsignedAttribute("level", &level);

			handler.add<Weapon>("weapon-" + name, name, level);
		}

		itemElement = itemElement->NextSiblingElement();
	}
}

