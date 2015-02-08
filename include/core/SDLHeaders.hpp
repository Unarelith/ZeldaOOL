/*
 * =====================================================================================
 *
 *       Filename:  SDLHeaders.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:07:57
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
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
