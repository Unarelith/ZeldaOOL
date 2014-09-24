/*
 * =====================================================================================
 *
 *       Filename:  TimeManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 19:34:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "SDLHeaders.hpp"
#include "TimeManager.hpp"

u32 TimeManager::lastFrameDate = 0;
u32 TimeManager::lag = 0;
u32 TimeManager::timeDropped = 0;
u32 TimeManager::now = 0;
u32 TimeManager::lastFrameDuration = 0;
u32 TimeManager::ticks = 0;
u32 TimeManager::timestep = 10;
u8 TimeManager::numUpdates = 0;

u32 TimeManager::getTicks(bool useRealTime) {
	if(useRealTime) {
		return SDL_GetTicks();
	} else {
		return ticks;
	}
}

void TimeManager::measureLastFrameDuration() {
	now = getTicks(true) - timeDropped;
	lastFrameDuration = now - lastFrameDate;
	lastFrameDate = now;
	lag += lastFrameDuration;
	
	if(lag >= 200) {
		timeDropped += lag - timestep;
		lag = timestep;
		lastFrameDate = getTicks(true) - timeDropped;
	}
}

void TimeManager::updateGame(std::function<void(void)> updateFunc) {
	numUpdates = 0;
	
	while(lag >= timestep && numUpdates < 10 && Application::window.isOpen()) {
		ticks += timestep;
		
		updateFunc();
		
		lag -= timestep;
		numUpdates++;
	}
}

void TimeManager::drawGame(std::function<void(void)> drawFunc) {
	if(numUpdates > 0) {
		drawFunc();
	}
	
	lastFrameDuration = getTicks(true) - timeDropped - lastFrameDate;
	
	if(lastFrameDuration < timestep) {
		SDL_Delay(timestep - lastFrameDuration);
	}
	
	now = 0;
	lastFrameDuration = 0;
}

