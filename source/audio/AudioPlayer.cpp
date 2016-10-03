/*
 * =====================================================================================
 *
 *       Filename:  AudioPlayer.cpp
 *
 *    Description:
 *
 *        Created:  28/04/2015 21:52:17
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "BackgroundMusic.hpp"
#include "ResourceHandler.hpp"
#include "SoundEffect.hpp"
#include "Timer.hpp"

void AudioPlayer::playMusic(const std::string &resourceName) {
	// ResourceHandler::getInstance().get<BackgroundMusic>(std::string("bgm-") + resourceName).play();
}

void AudioPlayer::playEffect(const std::string &resourceName, s8 channel) {
	// ResourceHandler::getInstance().get<SoundEffect>(std::string("sfx-") + resourceName).play(channel);
}

void AudioPlayer::repeatEffect(const std::string &resourceName, u8 delay) {
	// ResourceHandler::getInstance().get<SoundEffect>(std::string("sfx-") + resourceName).repeat(delay);
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

