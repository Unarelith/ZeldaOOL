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
#include "Sprite.hpp"

void SpriteAnimation::reset(u16 frameID) {
	m_timer.reset();
	m_timer.setTime(frameID * m_delay);
}

void SpriteAnimation::start() {
	m_timer.start();

	if(!Sprite::pause) m_isPaused = false;
}

void SpriteAnimation::stop() {
	m_timer.stop();

	if(!Sprite::pause) m_isPaused = true;
}

void SpriteAnimation::play() {
	if(Sprite::pause || m_isPaused) {
		stop();
	} else {
		start();
	}

	if(isFinished()) {
		if(m_isRepeated) {
			reset();
			start();
		} else {
			stop();
		}
	}
}

u16 SpriteAnimation::getFrame(u16 frameID) const {
	return m_frames.at(frameID);
}

u16 SpriteAnimation::currentFrame() const {
	u16 frameID = displayedFramesAmount();
	if(frameID >= m_frames.size()) {
		return getFrame(m_frames.size() - 1);
	} else {
		return getFrame(frameID);
	}
}

u16 SpriteAnimation::displayedFramesAmount() const {
	if (m_delay == 0)
		return 0;

	return m_timer.time() / m_delay;
}

const gk::Vector2i &SpriteAnimation::getFramePosition(u16 frameID) const {
	return m_positions.at(frameID);
}

const gk::Vector2i &SpriteAnimation::currentPosition() const {
	if(!isFinished()) {
		return getFramePosition(displayedFramesAmount());
	} else {
		return getFramePosition(m_frames.size() - 1);
	}
}

