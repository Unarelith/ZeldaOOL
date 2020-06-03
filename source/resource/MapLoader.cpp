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

#include "Map.hpp"
#include "MapLoader.hpp"
#include "SceneObjectLoader.hpp"

void MapLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *areaElement = doc.FirstChildElement("maps").FirstChildElement("area").ToElement();
	while(areaElement) {
		u16 area = areaElement->IntAttribute("id");

		tinyxml2::XMLElement *mapElement = areaElement->FirstChildElement("map");
		while(mapElement) {
			std::string name = mapElement->Attribute("name");
			std::string tilesetName = mapElement->Attribute("tileset");

			u16 x = mapElement->IntAttribute("x");
			u16 y = mapElement->IntAttribute("y");

			Tileset &tileset = handler.get<Tileset>(tilesetName);

			loadMap(name, area, x, y, tileset, handler);

			mapElement = mapElement->NextSiblingElement("map");
		}

		areaElement = areaElement->NextSiblingElement("area");
	}
}

#include "GrassFactory.hpp"
#include "TilesInfos.hpp"

void MapLoader::loadMap(const std::string &name, u16 area, u16 x, u16 y, Tileset &tileset, gk::ResourceHandler &handler) {
	gk::XMLFile doc("resources/maps/" + name + ".tmx");

	tinyxml2::XMLElement *mapElement = doc.FirstChildElement("map").ToElement();

	u16 width = mapElement->IntAttribute("width");
	u16 height = mapElement->IntAttribute("height");

	std::vector<u16> data;
	tinyxml2::XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
	while(tileElement) {
		s16 tileID = tileElement->IntAttribute("gid") - 1;

		data.push_back((tileID >= 0) ? tileID : 0);

		tileElement = tileElement->NextSiblingElement("tile");
	}

	Map &map = handler.add<Map>(makeName(area, x, y), area, x, y, width, height, tileset, data);

	for(u16 tileY = 0 ; tileY < height ; tileY++) {
		for(u16 tileX = 0 ; tileX < width ; tileX++) {
			u16 tileID = map.getTile(tileX, tileY);

			if(tileset.info()[tileID] == TilesInfos::TileType::GrassTile) {
				map.scene().addObject(GrassFactory::create(tileX, tileY));
			}
			else if(tileset.info()[tileID] == TilesInfos::TileType::LowGrassTile) {
				map.scene().addObject(GrassFactory::create(tileX, tileY, true));
			}
		}
	}

	SceneObjectLoader::load(name, map.scene());
}

