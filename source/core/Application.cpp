/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/09/2014 19:37:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "GameStateManager.hpp"
#include "TimeManager.hpp"

Window Application::window;

Application::Application() {
	window.open();
	
	GameStateManager::init();
}

Application::~Application() {
	GameStateManager::free();
	
	window.free();
}

void Application::run() {
	//Timer deltaTimer;
	
	while(window.isOpen()) {
		if(TimeManager::isTimeToUpdate()) {
			//TimeManager::dt = deltaTimer.time() / 1000.0f;
			
			//deltaTimer.reset();
			//deltaTimer.start();
			
			GameStateManager::top()->handleEvents();
			
			GameStateManager::top()->update();
			
			if(TimeManager::hasEnoughTimeToDraw()) {
				TimeManager::beginMeasuringRenderingTime();
				
				window.clear();
				
				GameStateManager::top()->render();
				
				window.update();
				
				TimeManager::beginMeasuringRenderingTime();
			}
		} else {
			TimeManager::waitUntilItsTime();
		}
		
		TimeManager::measureFrameDuration();
	}
}

