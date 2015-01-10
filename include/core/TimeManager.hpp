/*
 * =====================================================================================
 *
 *       Filename:  TimeManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 19:34:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef TIMEMANAGER_HPP_
#define TIMEMANAGER_HPP_

#include <functional>
#include <vector>

#include "Types.hpp"

namespace TimeManager {
	u32 getTicks(bool useRealTime = false);
	
	void measureLastFrameDuration();
	
	void updateGame(std::function<void(void)> updateFunc);
	
	void drawGame(std::function<void(void)> drawFunc);
	
	extern u32 lastFrameDate;
	extern u32 lag;
	extern u32 timeDropped;
	extern u32 now;
	extern u32 lastFrameDuration;
	extern u32 ticks;
	extern u32 timestep;
	extern u8 numUpdates;
}

#endif // TIMEMANAGER_HPP_
