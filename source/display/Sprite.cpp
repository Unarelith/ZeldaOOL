/*
 * =====================================================================================
 *
 *       Filename:  Sprite.cpp
 *
 *    Description:
 *
 *        Created:  17/01/2018 19:48:08
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/system/Exception.hpp>
#include "Sprite.hpp"

bool Sprite::pause = false;

Sprite::Sprite(const std::string &textureName, u16 frameWidth, u16 frameHeight, bool isAnimated) : Image(textureName) {
	m_frameWidth = frameWidth;
	m_frameHeight = frameHeight;

	setCurrentFrame(0);

	m_isAnimated = isAnimated;
}

void Sprite::load(const std::string &textureName, u16 frameWidth, u16 frameHeight, bool isAnimated) {
	Image::load(textureName);

	m_frameWidth = frameWidth;
	m_frameHeight = frameHeight;

	setCurrentFrame(0);

	m_isAnimated = isAnimated;
}

void Sprite::updateAnimations() {
	if (!m_animations.empty() && m_isAnimated) {
		if(m_currentAnimation >= m_animations.size()) {
			throw EXCEPTION("Trying to play inexistant animation:", m_currentAnimation, "| Animations:", m_animations.size());
		}

		m_animations.at(m_currentAnimation).play();

		setPosition(m_animations.at(m_currentAnimation).currentPosition().x,
		            m_animations.at(m_currentAnimation).currentPosition().y);

		setCurrentFrame(m_animations.at(m_currentAnimation).currentFrame());
	}
}

void Sprite::setCurrentFrame(u16 currentFrame) {
	u16 frameX = (currentFrame % (Image::width() / m_frameWidth)) * m_frameWidth;
	u16 frameY = (currentFrame / (Image::width() / m_frameWidth)) * m_frameHeight;

	setClipRect(frameX, frameY, m_frameWidth, m_frameHeight);

	m_currentFrame = currentFrame;
}

void Sprite::setCurrentFrame(u16 animID, u16 frameID) {
	setPosition(m_animations.at(animID).getFramePosition(frameID).x,
	            m_animations.at(animID).getFramePosition(frameID).y);

	setCurrentFrame(m_animations.at(animID).getFrame(frameID));
}

void Sprite::setCurrentAnimation(u16 currentAnimation) {
	// FIXME: Commenting this fixes sword spin animation
	// if (m_previousAnimation != currentAnimation)
	// 	m_animations[m_currentAnimation].reset();

	m_previousAnimation = m_currentAnimation;
	m_currentAnimation = currentAnimation;
}

