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
// #include <gk/audio/Music.hpp> // FIXME: GAMEKIT
// #include <gk/audio/Sound.hpp> // FIXME: GAMEKIT
#include <gk/core/XMLFile.hpp>
#include <gk/resource/ResourceHandler.hpp>

#include "AudioLoader.hpp"

void AudioLoader::load(const char *xmlFilename, gk::ResourceHandler &handler) {
	// FIXME: GAMEKIT
	// gk::XMLFile doc(xmlFilename);
    //
	// tinyxml2::XMLElement *musicElement = doc.FirstChildElement("audio").FirstChildElement("music").ToElement();
	// while(musicElement) {
	// 	std::string name = musicElement->Attribute("name");
	// 	std::string filename = "resources/audio/music/" + name + ".ogg";
    //
	// 	handler.add<gk::Music>("bgm-" + name, filename).setVolume(MIX_MAX_VOLUME / 2);
    //
	// 	musicElement = musicElement->NextSiblingElement("music");
	// }
    //
	// tinyxml2::XMLElement *soundEffectElement = doc.FirstChildElement("audio").FirstChildElement("soundeffect").ToElement();
	// while(soundEffectElement) {
	// 	std::string name = soundEffectElement->Attribute("name");
	// 	int channel = soundEffectElement->IntAttribute("channel");
	// 	std::string filename = "resources/audio/effects/" + name + ".wav";
    //
	// 	handler.add<gk::Sound>("sfx-" + name, filename).setChannel(channel);
    //
	// 	soundEffectElement = soundEffectElement->NextSiblingElement("soundeffect");
	// }
}

