/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:  
 *
 *        Created:  19/09/2014 19:37:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include "ApplicationStateStack.hpp"
#include "GameClock.hpp"
#include "KeyboardHandler.hpp"
#include "Window.hpp"

class Application {
	public:
		Application();
		
		void handleEvents();
		
		void run();
		
	private:
		ApplicationStateStack &m_stateStack;
		
		GameClock m_clock;
		
		KeyboardHandler m_keyboardHandler;
		
		Window m_window;
};

#endif // APPLICATION_HPP_
