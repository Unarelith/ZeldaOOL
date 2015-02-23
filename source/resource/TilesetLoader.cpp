/*
 * =====================================================================================
 *
 *       Filename:  TilesetLoader.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2015 16:32:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
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
		std::string filename = "graphics/tilesets/" + name + ".png";
		
		std::string configFile = "data/tilesets/" + name + ".xml";
		
		handler.add<Tileset>(name, filename, configFile);
		
		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}
