/*
 * =====================================================================================
 *
 *       Filename:  AudioPlayer.cpp
 *
 *    Description:
 *
 *        Created:  28/04/2015 21:52:17
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/resource/ResourceHandler.hpp>

#include "AudioPlayer.hpp"
#include "BackgroundMusic.hpp"
#include "SoundEffect.hpp"

bool AudioPlayer::s_muteState = false;

void AudioPlayer::playMusic(const std::string &resourceName) {
	if (!s_muteState)
		gk::ResourceHandler::getInstance().get<BackgroundMusic>(std::string("bgm-") + resourceName).play();
}

void AudioPlayer::playEffect(const std::string &resourceName, s8 channel) {
	if (!s_muteState)
		gk::ResourceHandler::getInstance().get<SoundEffect>(std::string("sfx-") + resourceName).play(channel);
}

void AudioPlayer::repeatEffect(const std::string &resourceName, u8 delay) {
	if (!s_muteState)
		gk::ResourceHandler::getInstance().get<SoundEffect>(std::string("sfx-") + resourceName).repeat(delay);
}

void AudioPlayer::pauseMusic() {
	Mix_PauseMusic();
}

void AudioPlayer::resumeMusic() {
	Mix_ResumeMusic();
}

bool AudioPlayer::isMusicPaused() {
	return Mix_PausedMusic();
}

bool AudioPlayer::isMusicPlaying() {
	return Mix_PlayingMusic();
}

