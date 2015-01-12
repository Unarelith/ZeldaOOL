/*
 * =====================================================================================
 *
 *       Filename:  MapLoader.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2015 15:05:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "MapLoader.hpp"
#include "MapManager.hpp"

void MapLoader::load(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);
	
	XMLElement *areaElement = doc.FirstChildElement("maps").FirstChildElement("area").ToElement();
	while(areaElement) {
		u16 area = areaElement->IntAttribute("id");
		
		XMLElement *mapElement = areaElement->FirstChildElement("map");
		while(mapElement) {
			std::string path = mapElement->Attribute("path");
			std::string tilesetName = mapElement->Attribute("tileset");
			
			u16 x = mapElement->IntAttribute("x");
			u16 y = mapElement->IntAttribute("y");
			
			u16 zoneID = mapElement->IntAttribute("zoneID");
			
			u16 tilesetID = (tilesetName == "plain") ? 0 : (tilesetName == "indoor") ? 1 : 2;
			Tileset *tileset = &MapManager::tilesets[tilesetID];
			
			handler.add<Map>(makeName(area, x, y), path, tileset, area, x, y);
			
			mapElement = mapElement->NextSiblingElement("map");
		}
		
		areaElement = areaElement->NextSiblingElement("area");
	}
}

