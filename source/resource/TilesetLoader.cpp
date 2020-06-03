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

#include "Tileset.hpp"
#include "TilesetLoader.hpp"

void TilesetLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *tilesetElement = doc.FirstChildElement("tilesets").FirstChildElement("tileset").ToElement();
	while(tilesetElement) {
		std::string name = tilesetElement->Attribute("name");
		std::string filename = "resources/graphics/tilesets/" + name + ".png";

		std::string configFile = "resources/config/tilesets/" + name + ".tsx";

		handler.add<Tileset>(name, filename, configFile);

		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}
