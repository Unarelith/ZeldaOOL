/*
 * =====================================================================================
 *
 *       Filename:  GameState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:17:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "GameState.hpp"
#include "SDLHeaders.hpp"

GameState::GameState(GameState *parent) {
	m_parent = parent;
}

GameState::~GameState() {
}

void GameState::handleEvents() {
	SDL_Event event;
	
	while(SDL_PollEvent(&event) != 0) {
		switch(event.type) {
			case SDL_QUIT:
				Application::window.close();
				break;
			default:
				break;
		}
	}
}
