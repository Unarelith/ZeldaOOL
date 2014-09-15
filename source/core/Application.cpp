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
#include "Timer.hpp"
#include "TimeManager.hpp"

GameWindow Application::window;

bool Application::quit = false;

Application::Application() {
	window.open();
	
	GameStateManager::init();
}

Application::~Application() {
	GameStateManager::free();
	
	window.close();
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
	Timer deltaTimer;
	
	while(!quit) {
		TimeManager::dt = deltaTimer.time() / 1000.0f;
		
		deltaTimer.reset();
		deltaTimer.start();
		
		handleEvents();
		
		GameStateManager::top()->update();
		
		window.clear();
		
		GameStateManager::top()->render();
		
		window.update();
	}
}

