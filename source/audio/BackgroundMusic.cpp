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
 *        Company:  
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "BackgroundMusic.hpp"
#include "ResourceHandler.hpp"

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

void BackgroundMusic::play(const std::string &resourceName) {
	ResourceHandler::getInstance().get<BackgroundMusic>(std::string("bgm-") + resourceName).play();
}

