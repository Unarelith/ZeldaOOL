/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimation.cpp
 *
 *    Description:  
 *
 *        Created:  27/04/2015 15:30:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Sprite.hpp"

SpriteAnimation::SpriteAnimation(std::vector<u16> frames, u16 delay)
	: m_frames(frames), m_delay(delay)
{
}

void SpriteAnimation::reset(u16 frame) {
	m_timer.reset();
	m_timer.setTime(frame * m_delay);
}

void SpriteAnimation::start() {
	m_timer.start();
}

void SpriteAnimation::stop() {
	m_timer.stop();
}

void SpriteAnimation::play() {
	if(isFinished()) {
		reset();
		start();
	}
	
	if(Sprite::pause) {
		stop();
	} else {
		start();
	}
}

u16 SpriteAnimation::currentFrameID() const {
	if(!isFinished()) {
		return m_frames[framesDisplayed()];
	} else {
		return 0;
	}
}

u16 SpriteAnimation::framesDisplayed() const {
	return m_timer.time() / m_delay;
}

