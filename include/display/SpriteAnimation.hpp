/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimation.hpp
 *
 *    Description:  
 *
 *        Created:  09/02/2015 02:40:21
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITEANIMATION_HPP_
#define SPRITEANIMATION_HPP_

#include <vector>

#include "Timer.hpp"

class SpriteAnimation {
	public:
		SpriteAnimation(std::vector<u16> frames, u16 delay)
			: m_frames(frames), m_delay(delay) {}
		
		void reset(u16 frame = 0) {
			m_timer.reset();
			m_timer.setTime(frame * m_delay);
		}
		
		void start() { m_timer.start(); }
		void stop() { m_timer.stop(); }
		
		u16 currentFrame() { return m_timer.time() / m_delay; }
		u16 currentFrameID() { return m_frames[currentFrame()]; }
		
		bool isPlaying() { return m_timer.isStarted(); }
		bool finished() { return currentFrame() >= m_frames.size(); }
		
		u16 delay() const { return m_delay; }
		
	private:
		std::vector<u16> m_frames;
		
		Timer m_timer;
		
		bool m_isPlaying = false;
		
		u16 m_delay = 0;
};

#endif // SPRITEANIMATION_HPP_
