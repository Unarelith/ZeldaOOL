/*
 * =====================================================================================
 *
 *       Filename:  BackgroundMusic.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2014 23:04:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "BackgroundMusic.hpp"

BackgroundMusic::BackgroundMusic() {
}

BackgroundMusic::BackgroundMusic(std::string filename) {
	open(filename);
}

BackgroundMusic::~BackgroundMusic() {
}

void BackgroundMusic::open(std::string filename) {
	m_music.openFromFile(filename);
	m_music.setLoop(true);
}

void BackgroundMusic::play() {
	m_music.play();
}

