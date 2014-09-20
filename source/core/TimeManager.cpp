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
#include <numeric>

#include "SDLHeaders.hpp"
#include "TimeManager.hpp"

u32 TimeManager::renderingTimeMean = 0;
u32 TimeManager::tempBeginRendering = 0;
u32 TimeManager::frameBegin = 0;
u32 TimeManager::frameEnd = 0;
u32 TimeManager::timeToWait = 0;
std::vector<u32> TimeManager::renderingTimeValues;
u16 TimeManager::maxFrameskip = 0;
u16 TimeManager::frameskip = 0;

u32 TimeManager::getTicks(bool useDeltaTime) {
	return SDL_GetTicks();
}

void TimeManager::beginMeasuringRenderingTime() {
	tempBeginRendering = SDL_GetTicks();
}

void TimeManager::endMeasuringRenderingTime() {
	u32 sum;
	
	renderingTimeValues.push_back(SDL_GetTicks() - tempBeginRendering);
	if(renderingTimeValues.size() > 10) {
		sum = std::accumulate(renderingTimeValues.begin(), renderingTimeValues.end(), 0);
		renderingTimeMean = sum / renderingTimeValues.size();
		renderingTimeValues.clear();
	}
}

bool TimeManager::isTimeToUpdate() {
	frameBegin = SDL_GetTicks();
	if(frameBegin - frameEnd < timeToWait) {
		return false;
	} else {
		timeToWait = 0;
		return true;
	}
}

bool TimeManager::hasEnoughTimeToDraw() {
	if(SDL_GetTicks() - frameBegin + renderingTimeMean > 17) {
		frameskip++;
		if(frameskip > maxFrameskip) {
			frameskip = 0;
			return true;
		} else {
			return false;
		}
	} else {
		return true;
	}
}

void TimeManager::waitUntilItsTime() {
	SDL_Delay(timeToWait - ((SDL_GetTicks() - frameBegin) + (frameBegin - frameEnd)));
}

void TimeManager::measureFrameDuration() {
	if(timeToWait == 0) {
		frameEnd = SDL_GetTicks();
		if(frameEnd - frameBegin <= 17) {
			timeToWait = 17 - (frameEnd - frameBegin);
		} else {
			timeToWait = 0;
		}
	}
}

