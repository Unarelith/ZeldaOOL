/*
 * =====================================================================================
 *
 *       Filename:  Application.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 18:37:56
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

#include <SFML/Graphics/RenderWindow.hpp>

#include "GameClock.hpp"
#include "GameStateStack.hpp"

class Application {
	public:
		Application();
		~Application();
		
		void handleEvents();
		
		void run();
		
		sf::RenderWindow &window() { return m_window; }
		
		static Application &getInstance() {
			static Application instance;
			return instance;
		}
		
	private:
		sf::RenderWindow m_window;
		sf::View m_defaultView;
		
		GameClock m_clock;
		
		GameStateStack &m_gameStateStack;
};

#endif // APPLICATION_HPP_
