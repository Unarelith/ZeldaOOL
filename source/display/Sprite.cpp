/*
 * =====================================================================================
 *
 *       Filename:  Sprite.cpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:39:29
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "Sprite.hpp"

bool Sprite::pause = false;

Sprite::Sprite(const std::string &filename, u16 frameWidth, u16 frameHeight) {
	load(filename, frameWidth, frameHeight);
}

void Sprite::load(const std::string &filename, u16 frameWidth, u16 frameHeight) {
	Image::load(filename);
	
	m_frameWidth = frameWidth;
	m_frameHeight = frameHeight;
}

void Sprite::addAnimation(std::initializer_list<u16> frames, u16 delay) {
	m_animations.emplace_back(frames, delay);
}

void Sprite::drawFrame(float x, float y, u16 frame) {
	u16 frameX = frame % (width() / m_frameWidth);
	u16 frameY = frame / (width() / m_frameWidth);
	
	m_lastFrameDisplayed = frame;
	
	setClipRect(frameX * m_frameWidth, frameY * m_frameHeight, m_frameWidth, m_frameHeight);
	
	draw(x, y, m_frameWidth, m_frameHeight);
}

void Sprite::resetAnimation(u16 anim, u16 frame) {
	m_animations[anim].reset(frame);
	m_currentAnimation = -1;
}

void Sprite::startAnimation(u16 anim) {
	m_animations[anim].start();
	m_currentAnimation = anim;
}

void Sprite::stopAnimation(u16 anim) {
	m_animations[anim].stop();
	m_currentAnimation = anim;
}

void Sprite::playAnimation(float x, float y, u16 anim) {
	if(anim > m_animations.size()) {
		throw EXCEPTION("Trying to play inexistant animation:", anim, "| Animations:", m_animations.size());
	}
	
	if(pause) stopAnimation(anim);
	else      startAnimation(anim);
	
	if(m_animations[anim].finished()) {
		resetAnimation(anim);
		startAnimation(anim);
	}
	
	drawFrame(x, y, m_animations[anim].currentFrameID());
}

