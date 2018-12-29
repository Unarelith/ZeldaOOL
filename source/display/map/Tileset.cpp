/*
 * =====================================================================================
 *
 *       Filename:  Tileset.cpp
 *
 *    Description:
 *
 *        Created:  12/01/2015 16:03:22
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <sstream>

#include <gk/core/XMLFile.hpp>
#include <gk/system/Exception.hpp>

#include "Tileset.hpp"

Tileset::Tileset(const std::string &filename, const std::string &configFile) {
	load(filename, configFile);
}

void Tileset::load(const std::string &filename, const std::string &configFile) {
	gk::Texture::loadFromFile(filename);

	gk::XMLFile doc(configFile);

	tinyxml2::XMLElement *tilesetElement = doc.FirstChildElement("tileset").ToElement();
	if (!tilesetElement)
		throw EXCEPTION("Invalid tileset:", configFile);

	std::string name = tilesetElement->Attribute("name");

	m_tileWidth = tilesetElement->UnsignedAttribute("tilewidth");
	m_tileHeight = tilesetElement->UnsignedAttribute("tileheight");

	u16 tileCount = tilesetElement->UnsignedAttribute("tilecount");
	m_tiles.resize(tileCount, Tile{0});

	tinyxml2::XMLElement *tileElement = tilesetElement->FirstChildElement("tile");
	while (tileElement) {
		u16 tileID = tileElement->UnsignedAttribute("id");
		u16 tileType = tileElement->UnsignedAttribute("type");

		Tile tile{tileType};

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

		m_info.push_back(tileType);
		setTile(tileID, tile);

		tileElement = tileElement->NextSiblingElement("tile");
	}
}

