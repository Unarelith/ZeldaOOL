/*
 * =====================================================================================
 *
 *       Filename:  SoundEffect.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:03:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "SoundEffect.hpp"

SoundEffect::SoundEffect() {
}

SoundEffect::SoundEffect(std::string filename) {
	load(filename);
}

SoundEffect::~SoundEffect() {
}

void SoundEffect::load(std::string filename) {
	m_sfx = Mix_LoadWAV(filename.c_str());
	if(!m_sfx) {
		error("Unable to load sound effect: %s (ERROR: %s)", filename.c_str(), Mix_GetError());
		exit(EXIT_FAILURE);
	}
}

void SoundEffect::play() {
	Mix_PlayChannel(-1, m_sfx, 0);
}

