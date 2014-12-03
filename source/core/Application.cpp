/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 18:38:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include <SFML/Window/Event.hpp>

#include "Application.hpp"

Application::Application() {
	m_window.create(sf::VideoMode(160 * 3, 144 * 3), "ZeldaSFML", sf::Style::Close);
	m_defaultView.reset(sf::FloatRect(0, 0, 160, 144));
	
	ResourceHandler::getInstance().loadResources();
	m_applicationStateStack = &ApplicationStateStack::getInstance();
}

Application::~Application() {
}

void Application::handleEvents() {
	sf::Event event;
	while(m_window.pollEvent(event)) {
		if(event.type == sf::Event::Closed) {
			m_window.close();
		}
		
		if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			m_window.close();
		}
	}
}

void Application::run() {
	while(m_window.isOpen()) {
		m_clock.measureLastFrameDuration();
		
		handleEvents();
		
		m_clock.updateGame([&]{
			m_applicationStateStack->top().update();
		});
		
		m_clock.drawGame([&]{
			m_window.setView(m_defaultView);
			m_window.clear();
			
			m_applicationStateStack->top().draw();
			
			m_window.display();
		});
	}
}

