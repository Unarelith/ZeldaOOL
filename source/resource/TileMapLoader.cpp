/*
 * =====================================================================================
 *
 *       Filename:  TileMapLoader.cpp
 *
 *    Description:
 *
 *        Created:  09/04/2018 01:09:36
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "TileMap.hpp"
#include "TileMapLoader.hpp"
#include "XMLFile.hpp"

void TileMapLoader::load(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *mapElement = doc.FirstChildElement("maps").FirstChildElement("map").ToElement();
	while(mapElement) {
		std::string name = mapElement->Attribute("name");
		std::string tilesetName = mapElement->Attribute("tileset");

		Tileset &tileset = handler.get<Tileset>("tileset-" + tilesetName);

		loadMap(name, "resources/maps/" + name + ".tmx", tileset, handler);

		mapElement = mapElement->NextSiblingElement("map");
	}
}

void TileMapLoader::loadMap(const std::string &name, const std::string &path, Tileset &tileset, ResourceHandler &handler) {
	XMLFile doc(path);

	tinyxml2::XMLElement *mapElement = doc.FirstChildElement("map").ToElement();

	u16 width = mapElement->IntAttribute("width");
	u16 height = mapElement->IntAttribute("height");

	std::vector<u16> data;
	tinyxml2::XMLElement *dataElement = mapElement->FirstChildElement("layer")->FirstChildElement("data");

	std::stringstream dataStream(dataElement->GetText());
	std::string token;

	while(std::getline(dataStream, token, ',')) {
		s16 tileID = std::stoi(token) - 1;

		data.push_back((tileID >= 0) ? tileID : 0);
	}

	TileMap &tileMap = handler.add<TileMap>("tilemap-" + name, width, height, tileset, data);

	tinyxml2::XMLElement *propertiesElement = mapElement->FirstChildElement("properties");
	if (propertiesElement) {
		tinyxml2::XMLElement *propertyElement = propertiesElement->FirstChildElement("property");
		tileMap.loadProperties(propertyElement);
	}
}

