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
#include "TilesetsData.hpp"
#include "XMLFile.hpp"

void TilesetLoader::load(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);
	
	XMLElement *tilesetElement = doc.FirstChildElement("tilesets").FirstChildElement("tileset").ToElement();
	while(tilesetElement) {
		std::string name = tilesetElement->Attribute("name");
		std::string filename = std::string("graphics/tilesets/") + name + ".png";
		
		//std::string configFile = std::string("data/tilesets/") + name + ".xml";
		
		// TODO: TO CHANGE LATER
		u16 *infos = (name == "plain") ? TilesetsData::plainInfo : (name == "indoor") ? TilesetsData::indoorInfo : TilesetsData::undergroundInfo;
		
		handler.add<Tileset>(name, filename, infos);
		
		XMLElement *animationElement = tilesetElement->FirstChildElement("animation");
		while(animationElement) {
			u16 delay = animationElement->IntAttribute("delay");
			
			std::vector<u16> frames;
			XMLElement *frameElement = animationElement->FirstChildElement("frame");
			while(frameElement) {
				frames.push_back(frameElement->IntAttribute("id"));
				
				frameElement = frameElement->NextSiblingElement("frame");
			}
			
			handler.get<Tileset>(name).addAnimation(frames, delay);
			
			animationElement = animationElement->NextSiblingElement("animation");
		}
		
		tilesetElement = tilesetElement->NextSiblingElement("tileset");
	}
}
