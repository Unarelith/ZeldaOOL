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

#include "OpenGLTestState.hpp"

Application::Application() {
	m_stateStack.push<OpenGLTestState>();
}

#include "Debug.hpp"

void Application::run() {
	while(m_window.isOpen() && m_stateStack.size() > 0) {
		EventHandler::processSDLEvents(m_window);
		
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

