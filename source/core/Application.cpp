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

bool Application::quit = false;

Application::Application() {
	
}

Application::~Application() {
}

void Application::run() {
	while(!quit) {
		m_window.clear();
		
		m_window.update();
	}
}

