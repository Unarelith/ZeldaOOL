/*
 * =====================================================================================
 *
 *       Filename:  MapLoader.cpp
 *
 *    Description:  
 *
 *        Created:  12/01/2015 15:05:28
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "MapLoader.hpp"
#include "SceneObjectLoader.hpp"

void MapLoader::load(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);
	
	XMLElement *areaElement = doc.FirstChildElement("maps").FirstChildElement("area").ToElement();
	while(areaElement) {
		u16 area = areaElement->IntAttribute("id");
		
		XMLElement *mapElement = areaElement->FirstChildElement("map");
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

void MapLoader::loadMap(const std::string &name, u16 area, u16 x, u16 y, Tileset &tileset, ResourceHandler &handler) {
	XMLFile doc("data/maps/" + name + ".tmx");
	
	XMLElement *mapElement = doc.FirstChildElement("map").ToElement();
	
	u16 width = mapElement->IntAttribute("width");
	u16 height = mapElement->IntAttribute("height");
	
	std::vector<u16> data;
	XMLElement *tileElement = mapElement->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
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

