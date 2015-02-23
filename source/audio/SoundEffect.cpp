/*
 * =====================================================================================
 *
 *       Filename:  SoundEffect.cpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:46:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "SoundEffect.hpp"

SoundEffect::SoundEffect(const std::string &filename) {
	load(filename);
}

void SoundEffect::load(const std::string &filename) {
	m_sfx.reset(Mix_LoadWAV(filename.c_str()));
	if(!m_sfx) {
		throw EXCEPTION("Unable to load sound effect", filename, ":", Mix_GetError());
	}
	
	m_timer.start();
}

void SoundEffect::play(s8 channel) {
	Mix_PlayChannel(channel, m_sfx.get(), 0);
}

void SoundEffect::playDelayed(u16 delay) {
	if(m_timer.time() > delay) {
		play();
		
		m_timer.reset();
		m_timer.start();
	}
}

