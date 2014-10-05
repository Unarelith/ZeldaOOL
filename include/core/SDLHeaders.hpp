/*
 * =====================================================================================
 *
 *       Filename:  SDLHeaders.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/09/2014 23:55:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SDLHEADERS_HPP_
#define SDLHEADERS_HPP_

#ifdef __ANDROID__
	#include "SDL.h"
	#include "SDL_image.h"
	#include "SDL_mixer.h"
#else
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
	#include <SDL2/SDL_mixer.h>
#endif

#endif // SDLHEADERS_HPP_
