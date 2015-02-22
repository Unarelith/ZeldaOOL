/*
 * =====================================================================================
 *
 *       Filename:  EventHandler.cpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:23:48
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "EventHandler.hpp"

void EventHandler::processSDLEvents(ApplicationWindow &window) {
	SDL_Event event;
	
	while(SDL_PollEvent(&event) != 0) {
		switch(event.type) {
			case SDL_QUIT:
				window.close();
				break;
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE) {
					window.close();
				}
				break;
			default:
				break;
		}
	}
}

