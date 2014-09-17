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

#include <vector>

#include "Types.hpp"

namespace TimeManager {
	u32 getTicks(bool useDeltaTime = true);
	
	void beginMeasuringRenderingTime();
	void endMeasuringRenderingTime();
	
	bool isTimeToUpdate();
	bool hasEnoughTimeToDraw();
	void waitUntilItsTime();
	void measureFrameDuration();
	
	extern double dt;
	
	extern u32 renderingTimeMean;
	extern u32 tempBeginRendering;
	extern u32 frameBegin;
	extern u32 frameEnd;
	extern u32 timeToWait;
	extern std::vector<u32> renderingTimeValues;
	extern u16 maxFrameskip;
	extern u16 frameskip;
};

#endif // TIMEMANAGER_HPP_
