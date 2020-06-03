/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
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

