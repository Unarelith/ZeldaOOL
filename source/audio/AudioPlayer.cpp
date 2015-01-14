/*
 * =====================================================================================
 *
 *       Filename:  AudioPlayer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/01/2015 00:56:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "AudioLoader.hpp"
#include "AudioPlayer.hpp"
#include "BackgroundMusic.hpp"
#include "SoundEffect.hpp"

void AudioPlayer::init() {
	ResourceHandler::getInstance().addType("data/config/audio.xml", AudioLoader());
}

void AudioPlayer::playEffect(const std::string &name) {
	ResourceHandler::getInstance().get<SoundEffect>(std::string("sfx-") + name).play();
}

void AudioPlayer::playMusic(const std::string &name) {
	ResourceHandler::getInstance().get<BackgroundMusic>(std::string("bgm-") + name).play();
}

