/*
 * =====================================================================================
 *
 *       Filename:  TimeManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 13:47:32
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

#include <SFML/System.hpp>

#include "Types.hpp"

namespace TimeManager {
	void beginMeasuringRenderingTime();
	void endMeasuringRenderingTime();
	
	bool isTimeToUpdate();
	bool hasEnoughTimeToDraw();
	void waitUntilItsTime();
	void measureFrameDuration();
	
	extern sf::Clock clock;
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
