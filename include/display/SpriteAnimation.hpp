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
#include "Vector2.hpp"

class SpriteAnimation {
	public:
		SpriteAnimation(std::vector<u16> frames, u16 delay)
			: m_frames(frames), m_positions(frames.size(), {0, 0}), m_delay(delay) {}
		SpriteAnimation(std::vector<u16> frames, std::vector<Vector2s16> positions, u16 delay)
			: m_frames(frames), m_positions(positions), m_delay(delay) {}
		
		void reset(u16 frameID = 0);
		
		void start();
		void stop();
		
		void play();
		
		u16 getFrame(u16 frameID) const;
		u16 currentFrame() const;
		u16 displayedFramesAmount() const;
		
		const Vector2f currentPosition() const;
		
		bool isPlaying() const { return m_timer.isStarted(); }
		bool isFinished() const { return displayedFramesAmount() >= m_frames.size(); }
		
		u32 size() const { return m_frames.size(); }
		
		u16 delay() const { return m_delay; }
		
	private:
		std::vector<u16> m_frames;
		std::vector<Vector2s16> m_positions;
		
		Timer m_timer;
		
		u16 m_delay = 0;
};

#endif // SPRITEANIMATION_HPP_
