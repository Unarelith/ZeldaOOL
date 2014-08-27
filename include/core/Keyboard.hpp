/*
 * =====================================================================================
 *
 *       Filename:  Keyboard.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/08/2014 12:33:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <map>

#include <SFML/Graphics.hpp>

#include "Types.hpp"

namespace Keyboard {
	enum Key {
		Left	= sf::Keyboard::Left,
		Right	= sf::Keyboard::Right,
		Up		= sf::Keyboard::Up,
		Down	= sf::Keyboard::Down,
		
		A		= sf::Keyboard::X,
		B		= sf::Keyboard::W,
		
		Start	= sf::Keyboard::Return,
		Select	= sf::Keyboard::BackSpace
	};
	
	bool isKeyPressed(Key key);
	
	bool isKeyPressedOnce(Key key);
	
	extern std::map<Key, u8> pressed;
};

#endif // KEYBOARD_HPP_
