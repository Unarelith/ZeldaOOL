/*
 * =====================================================================================
 *
 *       Filename:  SDLManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:07:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Debug.hpp"
#include "SDLManager.hpp"

void SDLManager::init() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		error("SDL init error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	
	if(!IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) {
		error("SDL_image init error: %s\n", IMG_GetError());
		exit(EXIT_FAILURE);
	}
	
	if(TTF_Init() < 0) {
		error("SDL_ttf init error: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
		error("SDL_mixer init error: %s\n", Mix_GetError());
		exit(EXIT_FAILURE);
	}
	
	Mix_AllocateChannels(32);
	Mix_Volume(1, MIX_MAX_VOLUME / 2);
	
	//if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2")) {
	//	warning("Warning: Linear interpolation not enabled!");
	//}
	
	//if(!SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1")) {
	//	warning("Warning: VSync not enabled!");
	//}
}

void SDLManager::free() {
	Mix_CloseAudio();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

