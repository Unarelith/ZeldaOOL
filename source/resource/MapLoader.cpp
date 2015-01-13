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

void MapLoader::load(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);
	
	XMLElement *areaElement = doc.FirstChildElement("maps").FirstChildElement("area").ToElement();
	while(areaElement) {
		u16 area = areaElement->IntAttribute("id");
		
		XMLElement *mapElement = areaElement->FirstChildElement("map");
		while(mapElement) {
			std::string path = mapElement->Attribute("path");
			std::string tileset = mapElement->Attribute("tileset");
			
			u16 x = mapElement->IntAttribute("x");
			u16 y = mapElement->IntAttribute("y");
			
			//u16 zoneID = mapElement->IntAttribute("zoneID");
			
			Tileset &tilesetRef = handler.get<Tileset>(tileset);
			handler.add<Map>(makeName(area, x, y), path, tilesetRef, area, x, y);
			
			mapElement = mapElement->NextSiblingElement("map");
		}
		
		areaElement = areaElement->NextSiblingElement("area");
	}
}

