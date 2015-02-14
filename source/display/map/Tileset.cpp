/*
 * =====================================================================================
 *
 *       Filename:  Tileset.cpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 22:02:59
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include <sstream>

#include "Tileset.hpp"
#include "XMLFile.hpp"

Tileset::Tileset(const std::string &filename, const std::string &configFile, u16 tileWidth, u16 tileHeight) : Texture(filename) {
	XMLFile doc(configFile);
	
	XMLElement *animationElement = doc.FirstChildElement("tileset").FirstChildElement("animation").ToElement();
	while(animationElement) {
		m_anims.emplace_back(animationElement->IntAttribute("delay"));
		
		std::istringstream frames(animationElement->Attribute("frames"));
		
		std::string tile;
		while(std::getline(frames, tile, ',')) {
			m_anims.back().frames.push_back(std::stoi(tile));
		}
		
		animationElement = animationElement->NextSiblingElement("animation");
	}
	
	
	XMLElement *infoElement = doc.FirstChildElement("tileset").FirstChildElement("info").ToElement();
	std::istringstream info(infoElement->GetText());
	
	std::string tile;
	while(std::getline(info, tile, ',')) {
		m_info.push_back(std::stoi(tile));
	}
	
	m_tileWidth  = tileWidth;
	m_tileHeight = tileHeight;
}

