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
#include "Debug.hpp"
#include "BackgroundMusic.hpp"

BackgroundMusic::BackgroundMusic() {
}

BackgroundMusic::BackgroundMusic(std::string filename) {
	open(filename);
}

BackgroundMusic::~BackgroundMusic() {
}

void BackgroundMusic::open(std::string filename) {
	m_music = Mix_LoadMUS(filename.c_str());
	if(!m_music) {
		error("Unable to load music: %s (ERROR: %s)", filename.c_str(), Mix_GetError());
		exit(EXIT_FAILURE);
	}
}

void BackgroundMusic::play() {
	Mix_PlayMusic(m_music, -1);
}

