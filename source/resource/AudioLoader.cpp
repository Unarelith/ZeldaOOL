/*
 * =====================================================================================
 *
 *       Filename:  AudioLoader.cpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:47:06
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
		std::string filename = "audio/music/" + name + ".ogg";
		
		handler.add<BackgroundMusic>("bgm-" + name, filename);
		
		musicElement = musicElement->NextSiblingElement("music");
	}
	
	XMLElement *soundEffectElement = doc.FirstChildElement("audio").FirstChildElement("soundeffect").ToElement();
	while(soundEffectElement) {
		std::string name = soundEffectElement->Attribute("name");
		std::string filename = "audio/effects/" + name + ".wav";
		
		handler.add<SoundEffect>("sfx-" + name, filename);
		
		soundEffectElement = soundEffectElement->NextSiblingElement("soundeffect");
	}
}

