/*
 * =====================================================================================
 *
 *       Filename:  Sprite.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 20:41:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
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
	
	m_lastFrameDisplayed = 0;
	
	m_currentAnimation = -1;
}

void Sprite::addAnimation(std::initializer_list<u16> frames, u16 delay) {
	m_animations.emplace_back(delay);
	
	m_animations.back().frames = frames;
}

void Sprite::drawFrame(float x, float y, u16 frame) {
	u16 frameX = frame % (width() / m_frameWidth);
	u16 frameY = frame / (width() / m_frameWidth);
	
	m_lastFrameDisplayed = frame;
	
	setClipRect(frameX * m_frameWidth, frameY * m_frameHeight, m_frameWidth, m_frameHeight);
	
	draw(x, y, m_frameWidth, m_frameHeight);
}

void Sprite::resetAnimation(u16 anim, u16 frame) {
	m_animations[anim].timer.reset();
	m_animations[anim].timer.setTime(frame * m_animations[anim].delay);
	m_animations[anim].isPlaying = false;
	m_currentAnimation = -1;
}

void Sprite::startAnimation(u16 anim) {
	m_animations[anim].timer.start();
	m_animations[anim].isPlaying = true;
	m_currentAnimation = anim;
}

void Sprite::stopAnimation(u16 anim) {
	m_animations[anim].timer.stop();
	m_animations[anim].isPlaying = false;
	m_currentAnimation = anim;
}

u16 Sprite::animationCurrentFrame(u16 anim) {
	return m_animations[anim].timer.time() / m_animations[anim].delay;
}

bool Sprite::animationAtEnd(u16 anim) {
	return animationCurrentFrame(anim) >= m_animations[anim].frames.size();
}

void Sprite::playAnimation(float x, float y, u16 anim) {
	if(m_animations.size() < anim) {
		throw EXCEPTION("Trying to play inexistant animation:", anim, "| Animations:", m_animations.size());
	}
	
	if(pause) {
		stopAnimation(anim);
		
		if(animationAtEnd(anim)) {
			resetAnimation(anim);
			startAnimation(anim);
		}
	} else {
		if(!m_animations[anim].isPlaying) {
			startAnimation(anim);
		}
		
		if(animationAtEnd(anim)) {
			resetAnimation(anim);
			startAnimation(anim);
		}
	}
	
	drawFrame(x, y, m_animations[anim].frames[animationCurrentFrame(anim)]);
}

