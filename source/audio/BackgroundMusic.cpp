/*
 * =====================================================================================
 *
 *       Filename:  BackgroundMusic.cpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 23:03:51
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/system/Exception.hpp>
#include "BackgroundMusic.hpp"

BackgroundMusic::BackgroundMusic(const std::string &filename) {
	load(filename);
}

void BackgroundMusic::load(const std::string &filename) {
	m_music.reset(Mix_LoadMUS(filename.c_str()));
	if(!m_music) {
		throw EXCEPTION("Unable to load music:", filename, ":", Mix_GetError());
	}
}

void BackgroundMusic::play() {
	Mix_PlayMusic(m_music.get(), -1);
}

