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

Sprite::Sprite(const std::string &textureName, s16 frameWidth, s16 frameHeight) {
	load(textureName, frameWidth, frameHeight);
}

void Sprite::load(const std::string &textureName, s16 frameWidth, s16 frameHeight) {
	Image::load(textureName);

	m_frameWidth  = (frameWidth  < 0) ? width()  : frameWidth;
	m_frameHeight = (frameHeight < 0) ? height() : frameHeight;
}

void Sprite::addAnimation(std::vector<u16> frames, u16 delay, bool isRepeated) {
	m_animations.emplace_back(frames, delay, isRepeated);
}

void Sprite::addAnimation(std::vector<u16> frames, std::vector<Vector2i> positions, u16 delay, bool isRepeated) {
	m_animations.emplace_back(frames, positions, delay, isRepeated);
}

void Sprite::drawFrame(float x, float y, u16 frame) {
	u16 frameX = frame % (width() / m_frameWidth);
	u16 frameY = frame / (width() / m_frameWidth);

	setClipRect(frameX * m_frameWidth, frameY * m_frameHeight, m_frameWidth, m_frameHeight);

	draw(x, y, m_frameWidth, m_frameHeight);
}

void Sprite::drawAnimationFrame(float x, float y, u16 animID, s16 frameID) {
	u16 frame;
	if(frameID == -1) {
		frame = m_animations[animID].currentFrame();
	} else {
		frame = m_animations[animID].getFrame(frameID);
	}

	x += m_animations[animID].currentPosition().x;
	y += m_animations[animID].currentPosition().y;

	m_currentAnimation = animID;

	drawFrame(x, y, frame);
}

void Sprite::playAnimation(float x, float y, u16 animID) {
	if(animID > m_animations.size()) {
		throw EXCEPTION("Trying to play inexistant animation:", animID, "| Animations:", m_animations.size());
	}

	m_animations[animID].play();

	if(!m_animations[animID].isFinished()) {
		drawAnimationFrame(x, y, animID);
	}
}

