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
#include "TimeManager.hpp"

sf::Clock TimeManager::clock;
double TimeManager::dt = 0;

u32 TimeManager::getTicks() {
	return clock.getElapsedTime().asMilliseconds() + 1000 * dt;
}

