/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 13:12:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Config.hpp"
#include "TimeManager.hpp"
#include "StateManager.hpp"
#include "Application.hpp"

sf::RenderWindow Application::window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), APP_NAME);

Application::Application() {
	window.setPosition(sf::Vector2i(425, 125));
	window.setSize(sf::Vector2u(WINDOW_WIDTH * 3, WINDOW_HEIGHT * 3));
	
	StateManager::init();
}

Application::~Application() {
	StateManager::free();
}

void Application::handleEvents() {
	sf::Event event;
	while(window.pollEvent(event)) {
		if(event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void Application::mainLoop() {
	window.setFramerateLimit(30);
	
	while(window.isOpen()) {
//		if(TimeManager::isTimeToUpdate()) {
			handleEvents();
			
			StateManager::top()->update();
			
//			if(TimeManager::hasEnoughTimeToDraw()) {
//				TimeManager::beginMeasuringRenderingTime();
				
				window.clear();
				
				StateManager::top()->render();
				
				window.display();
				
//				TimeManager::endMeasuringRenderingTime();
//			}
//		} else {
//			TimeManager::waitUntilItsTime();
//		}
		
//		TimeManager::measureFrameDuration();
	}
}

