/*
 * =====================================================================================
 *
 *       Filename:  SpriteAnimation.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 20:40:52
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
		SpriteAnimation(std::vector<u16> frames, u16 delay);
		
		void reset(u16 frame = 0);
		
		void start();
		void stop();
		
		void play();
		
		u16 currentFrameID() const;
		u16 framesDisplayed() const;
		
		bool isPlaying() const { return m_timer.isStarted(); }
		bool isFinished() const { return framesDisplayed() >= m_frames.size(); }
		
		u16 delay() const { return m_delay; }
		
	private:
		std::vector<u16> m_frames;
		
		Timer m_timer;
		
		u16 m_delay = 0;
};

#endif // SPRITEANIMATION_HPP_
