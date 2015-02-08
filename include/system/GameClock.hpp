/*
 * =====================================================================================
 *
 *       Filename:  GameClock.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:10:52
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GAMECLOCK_HPP_
#define GAMECLOCK_HPP_

#include <functional>

#include "Types.hpp"

class GameClock {
	public:
		static u32 getTicks(bool realTime = false);
		
		void measureLastFrameDuration();
		
		void updateGame(std::function<void(void)> updateFunc);
		
		void drawGame(std::function<void(void)> drawFunc);
		
	private:
		static const u8 timestep = 6;
		
		static u32 ticks;
		
		u32 m_lastFrameDate = 0;
		u32 m_lag = 0;
		u32 m_timeDropped = 0;
		u32 m_lastFrameDuration = 0;
		
		u8 m_numUpdates = 0;
};

#endif // GAMECLOCK_HPP_