/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 21:53:04
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include "ApplicationStateStack.hpp"
#include "ApplicationWindow.hpp"
#include "GameClock.hpp"
#include "KeyboardHandler.hpp"

class Application {
	public:
		Application();
		
		void run();
		
	private:
		ApplicationStateStack m_stateStack;
		
		ApplicationWindow m_window;
		
		GameClock m_clock;
		
		KeyboardHandler m_keyboardHandler;
};

#endif // APPLICATION_HPP_
