/*
 * =====================================================================================
 *
 *       Filename:  Application.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/11/2014 22:37:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include <ctime>

#include "Application.hpp"

Application::Application() {
	srand(time(nullptr));
}

Application::~Application() {
}

void Application::run() {
	while(m_window.isOpen()) {
		
	}
}

