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
#include "AudioLoader.hpp"
#include "MapState.hpp"
#include "ResourceHandler.hpp"
#include "TextureLoader.hpp"

Application::Application() : m_stateStack(ApplicationStateStack::getInstance()) {
	ResourceHandler::getInstance().addType("data/config/audio.xml", AudioLoader());
	ResourceHandler::getInstance().addType("data/config/textures.xml", TextureLoader());
	
	m_stateStack.push<MapState>();
}

void Application::handleEvents() {
	SDL_Event event;
	
	while(SDL_PollEvent(&event) != 0) {
		switch(event.type) {
			case SDL_QUIT:
				m_window.close();
				break;
			case SDL_KEYDOWN:
				if(event.key.keysym.sym == SDLK_ESCAPE) {
					m_window.close();
				}
				break;
			default:
				break;
		}
	}
}

void Application::run() {
	while(m_window.isOpen()) {
		handleEvents();
		
		m_clock.updateGame([&] {
			m_stateStack.top()->update();
		});
		
		m_clock.drawGame([&] {
			m_window.clear();
			
			m_stateStack.top()->render();
			
			m_window.update();
		});
	}
}

