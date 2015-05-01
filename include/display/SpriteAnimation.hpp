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
		SpriteAnimation(std::vector<u16> frames, u16 delay)
			: m_frames(frames), m_positions(frames.size(), {0, 0}), m_delay(delay) {}
		SpriteAnimation(std::vector<u16> frames, std::vector<std::pair<s16, s16>> positions, u16 delay)
			: m_frames(frames), m_positions(positions), m_delay(delay) {}
		
		void reset(u16 frame = 0);
		
		void start();
		void stop();
		
		void play();
		
		u16 getFrameID(u16 frame) const;
		u16 currentFrameID() const { return getFrameID(framesDisplayed()); }
		u16 framesDisplayed() const;
		
		const std::pair<s16, s16> currentPosition() const;
		
		bool isPlaying() const { return m_timer.isStarted(); }
		bool isFinished() const { return framesDisplayed() >= m_frames.size(); }
		
		u16 delay() const { return m_delay; }
		
	private:
		std::vector<u16> m_frames;
		std::vector<std::pair<s16, s16>> m_positions;
		
		Timer m_timer;
		
		u16 m_delay = 0;
};

#endif // SPRITEANIMATION_HPP_
