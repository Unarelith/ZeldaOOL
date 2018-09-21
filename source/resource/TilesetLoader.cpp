/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.cpp
 *
 *    Description:
 *
 *        Created:  12/01/2015 16:32:29
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Tileset.hpp"
#include "TilesetLoader.hpp"
#include "XMLFile.hpp"

void TilesetLoader::load(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);

	XMLElement *tilesetElement = doc.FirstChildElement("tilesets").FirstChildElement("tileset").ToElement();
	while(tilesetElement) {
		std::string name = tilesetElement->Attribute("name");
		std::string filename = "resources/graphics/tilesets/" + name + ".png";

		std::string configFile = "resources/config/tilesets/" + name + ".xml";

		handler.add<Tileset>(name, filename, configFile);

		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}
