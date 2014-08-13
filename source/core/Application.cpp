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
	m_paused = false;
	
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
		else if(event.type == sf::Event::LostFocus) {
			m_paused = true;
		}
		else if(event.type == sf::Event::GainedFocus) {
			m_paused = false;
		}
	}
}

void Application::mainLoop() {
	while(window.isOpen()) {
		if(TimeManager::isTimeToUpdate()) {
			handleEvents();
			
			if(m_paused) continue;
			
			StateManager::top()->update();
			
			if(TimeManager::hasEnoughTimeToDraw()) {
				TimeManager::beginMeasuringRenderingTime();
				
				window.clear();
				
				StateManager::top()->render();
				
				window.display();
				
				TimeManager::endMeasuringRenderingTime();
			}
		} else {
			TimeManager::waitUntilItsTime();
		}
		
		TimeManager::measureFrameDuration();
	}
}

