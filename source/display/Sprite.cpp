/*
 * =====================================================================================
 *
 *       Filename:  Sprite.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/07/2014 14:38:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Sprite.hpp"

Sprite::Sprite() {
}

Sprite::Sprite(std::string filename, u16 frameWidth, u16 frameHeight) {
	load(filename, frameWidth, frameHeight);
}

Sprite::~Sprite() {
}

void Sprite::load(std::string filename, u16 frameWidth, u16 frameHeight) {
	Image::load(filename);
	
	m_frameWidth = frameWidth;
	m_frameHeight = frameHeight;
	
	m_lastFrameDisplayed = 0;
}

void Sprite::drawFrame(s16 x, s16 y, u16 frame) {
	u16 frameX = frame % (width() / m_frameWidth);
	u16 frameY = frame / (width() / m_frameWidth);
	
	m_lastFrameDisplayed = frame;
	
	setClipRect(frameX * m_frameWidth, frameY * m_frameHeight, m_frameWidth, m_frameHeight);
	draw(x, y);
}

void Sprite::addAnimation(std::initializer_list<u16> frames, u16 delay) {
	m_animations.push_back(SpriteAnimation(delay));
	
	for(auto &it : frames) {
		m_animations.back().frames.push_back(it);
	}
}

void Sprite::resetAnimation(u16 anim) {
	m_animations[anim].timer.reset();
	m_animations[anim].isPlaying = false;
}

void Sprite::startAnimation(u16 anim) {
	m_animations[anim].timer.start();
	m_animations[anim].isPlaying = true;
}

void Sprite::stopAnimation(u16 anim) {
	m_animations[anim].timer.stop();
	m_animations[anim].isPlaying = false;
}

bool Sprite::animationAtEnd(u16 anim) {
	return m_animations[anim].timer.time() / m_animations[anim].delay >= m_animations[anim].frames.size();
}

bool Sprite::animationAtFrame(u16 anim, u16 frame) {
	return (u16)(m_animations[anim].timer.time() / m_animations[anim].delay) == frame;
}

void Sprite::playAnimation(s16 x, s16 y, u16 anim) {
	if(!m_animations[anim].isPlaying) {
		resetAnimation(anim);
		startAnimation(anim);
		m_animations[anim].isPlaying = true;
	}
	
	if(animationAtEnd(anim)) {
		resetAnimation(anim);
		startAnimation(anim);
	}
	
	u16 animToDraw = m_animations[anim].frames[(u16)(m_animations[anim].timer.time() / m_animations[anim].delay)];
	drawFrame(x, y, animToDraw);
}

