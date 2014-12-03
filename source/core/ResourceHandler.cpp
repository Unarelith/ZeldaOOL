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
#include "AnimatedMap.hpp"
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
	
	XMLElement *mapElement = resourcesElement->FirstChildElement("maps")->FirstChildElement("map");
	while(mapElement) {
		std::string name = mapElement->Attribute("name");
		std::string path = mapElement->Attribute("path");
		std::string tileset = mapElement->Attribute("tileset");
		
		add<AnimatedMap>(name, path, tileset);
		
		mapElement = mapElement->NextSiblingElement("map");
	}
}

