/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 19:50:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef KEYBOARDHANDLER_HPP_
#define KEYBOARDHANDLER_HPP_

#include <map>

#include <SFML/Window/Keyboard.hpp>

#include "InputHandler.hpp"

class KeyboardHandler : public InputHandler {
	public:
		KeyboardHandler();
		~KeyboardHandler();
		
		void update();
		
		bool isKeyPressed(GamePad::Key key);
		
	private:
		std::map<GamePad::Key, sf::Keyboard::Key> m_keys;
};

#endif // KEYBOARDHANDLER_HPP_
