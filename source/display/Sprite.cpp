/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#include <gk/core/Exception.hpp>
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

