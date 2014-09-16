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
#include "SDLHeaders.hpp"
#include "TimeManager.hpp"

double TimeManager::dt = 0;

u32 TimeManager::getTicks(bool useDeltaTime) {
	if(useDeltaTime) {
		return SDL_GetTicks() + 1000 * dt;
	} else {
		return SDL_GetTicks();
	}
}

