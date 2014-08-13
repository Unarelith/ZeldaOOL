/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 13:09:29
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

#include <SFML/Graphics.hpp>

class Application {
	public:
		Application();
		~Application();
		
		void handleEvents();
		void mainLoop();
		
		static sf::RenderWindow window;
		
	private:
		bool m_paused;
};

#endif // APPLICATION_HPP_
