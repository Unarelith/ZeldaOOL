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
			: m_frames(frames), m_positions(frames.size(), {0, 0}), m_delay(delay) {}
		
		SpriteAnimation(std::vector<u16> frames, std::vector<std::pair<s16, s16>> positions, u16 delay)
			: m_frames(frames), m_positions(positions), m_delay(delay) {}
		
		void reset(u16 frame = 0) {
			m_timer.reset();
			m_timer.setTime(frame * m_delay);
		}
		
		void start() { m_timer.start(); }
		void stop() { m_timer.stop(); }
		
		u16 currentFrame() const { return m_timer.time() / m_delay; }
		u16 currentFrameID() const { return (!finished()) ? m_frames[currentFrame()] : 0; }
		
		std::pair<s16, s16> currentPosition() const {
			if(!finished()) return m_positions[currentFrame()];
			else return {0, 0};
		}
		
		bool isPlaying() const { return m_timer.isStarted(); }
		bool finished() const { return currentFrame() >= m_frames.size(); }
		
		u16 delay() const { return m_delay; }
		
	private:
		std::vector<u16> m_frames;
		std::vector<std::pair<s16, s16>> m_positions;
		
		Timer m_timer;
		
		bool m_isPlaying = false;
		
		u16 m_delay = 0;
};

#endif // SPRITEANIMATION_HPP_
