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
	
	std::string info = doc.FirstChildElement(name.c_str()).FirstChildElement("info").ToElement()->GetText();
	s16 currentPos = 0;
	while(true) {
		std::string tile;
		if(info.find_first_of(',', currentPos) != std::string::npos) {
			tile = info.substr(currentPos, info.find_first_of(',', currentPos) - currentPos);
		} else {
			tile = info.substr(currentPos);
		}
		
		m_info.push_back(std::stoi(tile));
		currentPos = info.find_first_of(',', currentPos);
		
		if(currentPos != (s16)std::string::npos) {
			currentPos++;
		} else {
			break;
		}
	}
}

void Tileset::addAnimation(std::initializer_list<u16> frames, u16 delay) {
	m_anims.push_back(TileAnimation(delay));
	
	for(auto &it : frames) {
		m_anims.back().frames.push_back(it);
	}
}

