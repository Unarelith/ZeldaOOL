/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/09/2014 23:46:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include "GameWindow.hpp"

class Application {
	public:
		Application();
		~Application();
		
		void run();
		
		static bool quit;
		
	private:
		GameWindow m_window;
};

#endif // APPLICATION_HPP_
