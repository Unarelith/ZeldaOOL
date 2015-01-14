/*
 * =====================================================================================
 *
 *       Filename:  AudioLoader.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/01/2015 00:34:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "AudioLoader.hpp"
#include "BackgroundMusic.hpp"
#include "SoundEffect.hpp"
#include "XMLFile.hpp"

void AudioLoader::load(const std::string &xmlFilename, ResourceHandler &handler) {
	XMLFile doc(xmlFilename);
	
	XMLElement *musicElement = doc.FirstChildElement("audio").FirstChildElement("music").ToElement();
	while(musicElement) {
		std::string name = musicElement->Attribute("name");
		std::string filename = std::string("audio/music/") + name + ".ogg";
		
		handler.add<BackgroundMusic>(std::string("bgm-") + name, filename);
		
		musicElement = musicElement->NextSiblingElement("music");
	}
	
	XMLElement *soundEffectElement = doc.FirstChildElement("audio").FirstChildElement("soundeffect").ToElement();
	while(soundEffectElement) {
		std::string name = soundEffectElement->Attribute("name");
		std::string filename = std::string("audio/effects/") + name + ".wav";
		
		handler.add<SoundEffect>(std::string("sfx-") + name, filename);
		
		soundEffectElement = soundEffectElement->NextSiblingElement("soundeffect");
	}
}

