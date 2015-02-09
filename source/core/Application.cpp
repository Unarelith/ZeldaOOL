/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 21:54:38
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "EventHandler.hpp"
#include "ResourceHandler.hpp"
#include "TextureLoader.hpp"

#include "DisplayTestState.hpp"
#include "OpenGLTestState.hpp"

Application::Application() {
	ResourceHandler::getInstance().addType<TextureLoader>("data/config/textures.xml");
	
	//m_stateStack.push<OpenGLTestState>();
	m_stateStack.push<DisplayTestState>();
}

void Application::run() {
	while(m_window.isOpen()) {
		EventHandler::processSDLEvents(m_window);
		
		if(m_stateStack.size() > 0) {
			m_clock.updateGame([&] {
				m_stateStack.top()->update();
			});
			
			m_clock.drawGame([&] {
				m_window.clear();
				
				m_stateStack.top()->draw();
				
				m_window.update();
			});
		}
	}
}

