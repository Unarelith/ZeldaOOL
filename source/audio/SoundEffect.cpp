/*
 * =====================================================================================
 *
 *       Filename:  SoundEffect.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/09/2014 22:17:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "SoundEffect.hpp"

SoundEffect::SoundEffect() {
}

SoundEffect::SoundEffect(std::string filename) {
	load(filename);
}

SoundEffect::~SoundEffect() {
}

void SoundEffect::load(std::string filename) {
	m_buffer.loadFromFile(filename);
	m_sfx.setBuffer(m_buffer);
}

void SoundEffect::play() {
	m_sfx.play();
}

