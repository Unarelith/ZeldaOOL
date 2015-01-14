/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/09/2014 19:37:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include "GameClock.hpp"
#include "Window.hpp"

class Application {
	public:
		Application();
		~Application();
		
		void handleEvents();
		
		void run();
		
	private:
		GameClock m_clock;
		
		Window m_window;
};

#endif // APPLICATION_HPP_
