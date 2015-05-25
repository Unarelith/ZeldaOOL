/*
 * =====================================================================================
 *
 *       Filename:  Sprite.cpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 20:41:07
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "Sprite.hpp"

bool Sprite::pause = false;

Sprite::Sprite(const std::string &textureName, u16 frameWidth, u16 frameHeight) {
	load(textureName, frameWidth, frameHeight);
}

void Sprite::load(const std::string &textureName, u16 frameWidth, u16 frameHeight) {
	Image::load(textureName);
	
	m_frameWidth = frameWidth;
	m_frameHeight = frameHeight;
}

void Sprite::addAnimation(std::vector<u16> frames, u16 delay) {
	m_animations.emplace_back(frames, delay);
}

void Sprite::addAnimation(std::vector<u16> frames, std::vector<Vector2s16> positions, u16 delay) {
	m_animations.emplace_back(frames, positions, delay);
}

void Sprite::drawFrame(Vector2f position, u16 frame) {
	u16 frameX = frame % (width() / m_frameWidth);
	u16 frameY = frame / (width() / m_frameWidth);
	
	setClipRect(FloatRect{frameX * m_frameWidth, frameY * m_frameHeight, m_frameWidth, m_frameHeight});
	
	draw(position, m_frameWidth, m_frameHeight);
}

void Sprite::drawAnimationFrame(Vector2f position, u16 animID, s16 frameID) {
	u16 frame;
	if(frameID == -1) {
		frame = m_animations[animID].currentFrame();
	} else {
		frame = m_animations[animID].getFrame(frameID);
	}
	
	position += m_animations[animID].currentPosition();
	
	m_currentAnimation = animID;
	
	drawFrame(position, frame);
}

void Sprite::playAnimation(Vector2f position, u16 animID) {
	if(animID > m_animations.size()) {
		throw EXCEPTION("Trying to play inexistant animation:", animID, "| Animations:", m_animations.size());
	}
	
	m_animations[animID].play();
	
	drawAnimationFrame(position, animID);
}

