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

#include "Window.hpp"

class Application {
	public:
		Application();
		~Application();
		
		void run();
		
		static Window window;
		
		static Application &getInstance() {
			static Application instance;
			return instance;
		}
};

#endif // APPLICATION_HPP_
