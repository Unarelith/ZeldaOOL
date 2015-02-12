/*
 * =====================================================================================
 *
 *       Filename:  AudioTestState.cpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 19:29:53
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationWindow.hpp"
#include "AudioPlayer.hpp"
#include "AudioTestState.hpp"
#include "GamePad.hpp"

void AudioTestState::update() {
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		if(!AudioPlayer::isMusicPaused()) {
			AudioPlayer::playMusic(m_musics[m_musicID]);
		} else {
			AudioPlayer::resumeMusic();
		}
	}
	else if(GamePad::isKeyPressedOnce(GameKey::B)) {
		AudioPlayer::pauseMusic();
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Left)) {
		m_musicID--;
		if(m_musicID < 0) m_musicID = m_musics.size() - 1;
		AudioPlayer::playMusic(m_musics[m_musicID]);
	}
	else if(GamePad::isKeyPressedOnce(GameKey::Right)) {
		m_musicID++;
		if((u8)m_musicID >= m_musics.size()) m_musicID = 0;
		AudioPlayer::playMusic(m_musics[m_musicID]);
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Up)) {
		// TODO: Volume up here
	}
	else if(GamePad::isKeyPressedOnce(GameKey::Down)) {
		// TODO: Volume down here
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Start)) {
		AudioPlayer::playEffect("menuSelect");
	}
}

void AudioTestState::draw() {
	m_font.drawString(4, 0,   "A:     Play music");
	m_font.drawString(4, 16,  "B:     Pause music");
	m_font.drawString(4, 32,  "Left:  Prev music");
	m_font.drawString(4, 48,  "Right: Next music");
	m_font.drawString(4, 64,  "Up:    Volume up");
	m_font.drawString(4, 80,  "Down:  Volume down");
	m_font.drawString(4, 96,  "Start: Play a sound effect");
	m_font.drawString(4, 112, "Current music: ");
	m_font.drawString(ApplicationWindow::screenWidth - m_musics[m_musicID].size() * 8, 124, m_musics[m_musicID]);
}

