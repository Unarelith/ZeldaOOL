/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.cpp
 *
 *    Description:
 *
 *        Created:  08/04/2018 20:42:20
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "Tileset.hpp"
#include "TilesetLoader.hpp"
#include "XMLFile.hpp"

void TilesetLoader::load(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *tilesetElement = doc.FirstChildElement("tilesets").FirstChildElement("tileset").ToElement();
	while (tilesetElement) {
		std::string name = tilesetElement->Attribute("name");

		loadTileset("resources/config/tilesets/" + name + ".tsx", handler);

		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}

void TilesetLoader::loadTileset(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *tilesetElement = doc.FirstChildElement("tileset").ToElement();
	if (!tilesetElement)
		throw EXCEPTION("Invalid tileset:", xmlFilename);

	std::string name = tilesetElement->Attribute("name");

	u16 tileWidth = tilesetElement->UnsignedAttribute("tilewidth");
	u16 tileHeight = tilesetElement->UnsignedAttribute("tileheight");
	u16 tileCount = tilesetElement->UnsignedAttribute("tilecount");

	Tileset &tileset = handler.add<Tileset>("tileset-" + name, name, tileWidth, tileHeight, tileCount, handler.get<Texture>("tilesets-" + name));

	tinyxml2::XMLElement *tileElement = tilesetElement->FirstChildElement("tile");
	while (tileElement) {
		u16 tileID = tileElement->UnsignedAttribute("id");
		u16 tileType = tileElement->UnsignedAttribute("type");

		Tile tile{tileType};

		tinyxml2::XMLElement *propertiesElement = tileElement->FirstChildElement("properties");
		if (propertiesElement) {
			tinyxml2::XMLElement *propertyElement = propertiesElement->FirstChildElement("property");
			tile.loadProperties(propertyElement);
		}

		tinyxml2::XMLElement *animationElement = tileElement->FirstChildElement("animation");
		if (animationElement) {
			tinyxml2::XMLElement *frameElement = animationElement->FirstChildElement("frame");
			while (frameElement) {
				u16 frameTileID = frameElement->UnsignedAttribute("tileid");
				u16 frameDuration = frameElement->UnsignedAttribute("duration");

				tile.addAnimationFrame(frameTileID, frameDuration);

				frameElement = frameElement->NextSiblingElement("frame");
			}
		}

		tileset.setTile(tileID, tile);

		tileElement = tileElement->NextSiblingElement("tile");
	}
}

