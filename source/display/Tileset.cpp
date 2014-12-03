/*
 * =====================================================================================
 *
 *       Filename:  Tileset.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 15:39:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Tileset.hpp"
#include "XMLFile.hpp"

Tileset::Tileset() {
}

Tileset::Tileset(std::string name) {
	load(name);
}

void Tileset::load(std::string name) {
	m_texture.loadFromFile(std::string("graphics/tilesets/") + name + ".png");
	
	XMLFile doc(std::string("data/tilesets/") + name + ".xml");
	
	XMLElement *animationElement = doc.FirstChildElement(name.c_str()).FirstChildElement("animation").ToElement();
	while(animationElement) {
		m_anims.push_back(TileAnimation(animationElement->IntAttribute("delay")));
		
		XMLElement *frameElement = animationElement->FirstChildElement("frame");
		while(frameElement) {
			m_anims.back().frames.push_back(frameElement->IntAttribute("id"));
			
			frameElement = frameElement->NextSiblingElement("frame");
		}
		
		animationElement = animationElement->NextSiblingElement("animation");
	}
}

void Tileset::addAnimation(std::initializer_list<u16> frames, u16 delay) {
	m_anims.push_back(TileAnimation(delay));
	
	for(auto &it : frames) {
		m_anims.back().frames.push_back(it);
	}
}

