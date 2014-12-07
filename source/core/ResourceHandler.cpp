/*
 * =====================================================================================
 *
 *       Filename:  ResourceHandler.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/12/2014 17:30:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "ResourceHandler.hpp"
#include "Tileset.hpp"
#include "XMLFile.hpp"

// Template specializations for ResourceHandler::add
#include "ResourceHandler.inl"

ResourceHandler::ResourceHandler() {
}

ResourceHandler::~ResourceHandler() {
}

void ResourceHandler::loadResources() {
	XMLFile doc("data/config/resources.xml");
	XMLElement *resourcesElement = doc.FirstChildElement("resources").ToElement();
	
	XMLElement *textureElement = resourcesElement->FirstChildElement("textures")->FirstChildElement("texture");
	while(textureElement) {
		std::string name = textureElement->Attribute("name");
		std::string path = textureElement->Attribute("path");
		
		add<sf::Texture>(name, path);
		
		textureElement = textureElement->NextSiblingElement("texture");
	}
	
	XMLElement *tilesetElement = resourcesElement->FirstChildElement("tilesets")->FirstChildElement("tileset");
	while(tilesetElement) {
		std::string name = tilesetElement->Attribute("name");
		
		add<Tileset>(name, name);
		
		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
	
	XMLElement *areaElement = resourcesElement->FirstChildElement("maps")->FirstChildElement("area");
	while(areaElement) {
		u16 area = areaElement->IntAttribute("id");
		
		XMLElement *mapElement = areaElement->FirstChildElement("map");
		while(mapElement) {
			std::string path = mapElement->Attribute("path");
			std::string tileset = mapElement->Attribute("tileset");
			
			u16 x = mapElement->IntAttribute("x");
			u16 y = mapElement->IntAttribute("y");
			
			u16 zoneID = mapElement->IntAttribute("zoneID");
			
			std::string name = std::to_string(area) + "-" + std::to_string(x) + "-" + std::to_string(y);
			
			add<Map>(name, path, tileset, area, x, y, zoneID);
			
			mapElement = mapElement->NextSiblingElement("map");
		}
		
		areaElement = areaElement->NextSiblingElement("area");
	}
}

