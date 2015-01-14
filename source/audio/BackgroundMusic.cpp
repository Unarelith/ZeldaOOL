/*
 * =====================================================================================
 *
 *       Filename:  BackgroundMusic.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:03:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "BackgroundMusic.hpp"

BackgroundMusic::BackgroundMusic(BackgroundMusic &&music) {
	m_music = music.m_music;
	music.m_music = nullptr;
}

BackgroundMusic::BackgroundMusic(const std::string &filename) {
	load(filename);
}

BackgroundMusic::~BackgroundMusic() {
	if(m_music) Mix_FreeMusic(m_music);
}

void BackgroundMusic::load(const std::string &filename) {
	m_music = Mix_LoadMUS(filename.c_str());
	if(!m_music) {
		throw EXCEPTION("Unable to load music:", filename, ":", Mix_GetError());
	}
}

void BackgroundMusic::play() {
	Mix_PlayMusic(m_music, -1);
}

