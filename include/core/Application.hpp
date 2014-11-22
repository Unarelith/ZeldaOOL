/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/11/2014 22:37:08
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

#include "Window.hpp"

class Application {
	public:
		Application();
		~Application();
		
		void run();
		
	private:
		Window m_window;
};

#endif // APPLICATION_HPP_
