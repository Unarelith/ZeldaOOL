/*
 * =====================================================================================
 *
 *       Filename:  TimeManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 13:47:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "TimeManager.hpp"

sf::Clock TimeManager::clock;
u32 TimeManager::renderingTimeMean = 0;
u32 TimeManager::tempBeginRendering = 0;
u32 TimeManager::frameBegin = 0;
u32 TimeManager::frameEnd = 0;
u32 TimeManager::timeToWait = 0;
std::vector<u32> TimeManager::renderingTimeValues;
u16 TimeManager::maxFrameskip = 5;
u16 TimeManager::frameskip = 0;
u16 TimeManager::currentFrameDuration = 33;

void TimeManager::beginMeasuringRenderingTime() {
	tempBeginRendering = clock.getElapsedTime().asMilliseconds();
}

void TimeManager::endMeasuringRenderingTime() {
	u32 sum;
	
	renderingTimeValues.push_back(clock.getElapsedTime().asMilliseconds() - tempBeginRendering);
	if(renderingTimeValues.size() > 10) {
		sum = std::accumulate(renderingTimeValues.begin(), renderingTimeValues.end(), 0);
		renderingTimeMean = sum / renderingTimeValues.size();
		//debug("Rendering time mean: %ld", renderingTimeMean);
		renderingTimeValues.clear();
	}
}

bool TimeManager::isTimeToUpdate() {
	frameBegin = clock.getElapsedTime().asMilliseconds();
	if(frameBegin - frameEnd < timeToWait) {
		return false;
	} else {
		timeToWait = 0;
		return true;
	}
}

bool TimeManager::hasEnoughTimeToDraw() {
	if(clock.getElapsedTime().asMilliseconds() - frameBegin + renderingTimeMean > 33) {
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
	debug("Time to wait: %ld", timeToWait - ((clock.getElapsedTime().asMilliseconds() - frameBegin) + (frameBegin - frameEnd)));
	sf::sleep(sf::milliseconds(timeToWait - ((clock.getElapsedTime().asMilliseconds() - frameBegin) + (frameBegin - frameEnd))));
}

void TimeManager::measureFrameDuration() {
	if(timeToWait == 0) {
		frameEnd = clock.getElapsedTime().asMilliseconds();
		if(frameEnd - frameBegin <= 33) {
			timeToWait = 33 - (frameEnd - frameBegin);
			currentFrameDuration = 33;
		} else {
			timeToWait = 0;
			currentFrameDuration = frameEnd - frameBegin + 1;
		}
	}
}

