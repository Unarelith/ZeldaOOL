/*
 * =====================================================================================
 *
 *       Filename:  AudioLoader.cpp
 *
 *    Description:
 *
 *        Created:  14/01/2015 00:34:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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
		std::string filename = "resources/audio/music/" + name + ".ogg";

		handler.add<BackgroundMusic>("bgm-" + name, filename);

		musicElement = musicElement->NextSiblingElement("music");
	}

	XMLElement *soundEffectElement = doc.FirstChildElement("audio").FirstChildElement("soundeffect").ToElement();
	while(soundEffectElement) {
		std::string name = soundEffectElement->Attribute("name");
		std::string filename = "resources/audio/effects/" + name + ".wav";

		handler.add<SoundEffect>("sfx-" + name, filename);

		soundEffectElement = soundEffectElement->NextSiblingElement("soundeffect");
	}
}

