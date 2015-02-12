/*
 * =====================================================================================
 *
 *       Filename:  AudioPlayer.cpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:46:55
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "BackgroundMusic.hpp"
#include "ResourceHandler.hpp"
#include "SoundEffect.hpp"

void AudioPlayer::playMusic(const std::string &resourceName) {
	ResourceHandler::getInstance().get<BackgroundMusic>(std::string("bgm-") + resourceName).play();
}

void AudioPlayer::playEffect(const std::string &resourceName, s8 channel) {
	ResourceHandler::getInstance().get<SoundEffect>(std::string("sfx-") + resourceName).play(channel);
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

