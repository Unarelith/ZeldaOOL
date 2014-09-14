/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/09/2014 23:46:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "GameStateManager.hpp"

bool Application::quit = false;

Application::Application() {
	GameStateManager::init();
}

Application::~Application() {
	GameStateManager::free();
}

void Application::handleEvents() {
	SDL_Event event;
	
	while(SDL_PollEvent(&event) != 0) {
		switch(event.type) {
			case SDL_QUIT:
				Application::quit = true;
				break;
			default:
				break;
		}
	}
}

void Application::run() {
	while(!quit) {
		handleEvents();
		
		GameStateManager::top()->update();
		
		m_window.clear();
		
		GameStateManager::top()->render();
		
		m_window.update();
	}
}

