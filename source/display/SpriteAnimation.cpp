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

u16 SpriteAnimation::getFrameID(u16 frame) const {
	//if(!isFinished()) {
		return m_frames[frame];
	//} else {
	//	return m_frames[0];
	//}
}

u16 SpriteAnimation::framesDisplayed() const {
	return m_timer.time() / m_delay;
}


const std::pair<s16, s16> SpriteAnimation::currentPosition() const {
	if(!isFinished()) {
		return m_positions[framesDisplayed()];
	} else {
		return std::pair<s16, s16>(0, 0);
	}
}
