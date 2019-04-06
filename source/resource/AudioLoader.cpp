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
#include <SFML/Audio.hpp>

#include <gk/core/XMLFile.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "AudioLoader.hpp"

void AudioLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	gk::XMLFile doc(xmlFilename);

	tinyxml2::XMLElement *musicElement = doc.FirstChildElement("audio").FirstChildElement("music").ToElement();
	while(musicElement) {
		std::string name = musicElement->Attribute("name");
		std::string filename = "resources/audio/music/" + name + ".ogg";

		auto &music = handler.add<sf::Music>("bgm-" + name);
		music.openFromFile(filename);
		music.setVolume(music.getVolume() / 2);

		musicElement = musicElement->NextSiblingElement("music");
	}

	tinyxml2::XMLElement *soundEffectElement = doc.FirstChildElement("audio").FirstChildElement("soundeffect").ToElement();
	while(soundEffectElement) {
		std::string name = soundEffectElement->Attribute("name");
		// int channel = soundEffectElement->IntAttribute("channel");
		std::string filename = "resources/audio/effects/" + name + ".wav";

		sf::SoundBuffer &buffer = handler.add<sf::SoundBuffer>("soundbuffer-" + name);
		buffer.loadFromFile("resources/audio/sound/" + name + ".wav");

		handler.add<sf::Sound>("sfx-" + name, buffer);
		// sound.setChannel(channel);

		soundEffectElement = soundEffectElement->NextSiblingElement("soundeffect");
	}
}

