/*
 * =====================================================================================
 *
 *       Filename:  Keyboard.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/08/2014 12:34:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"

std::map<Keyboard::Key, u8> Keyboard::pressed;

bool Keyboard::isKeyPressed(Key key) {
	return sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key);
}

bool Keyboard::isKeyPressedOnce(Key key) {
	if(sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key)) {
		if(!pressed[key]) {
			pressed[key] = 1;
			return true;
		} else {
			return false;
		}
	} else {
		pressed[key] = 0;
		return false;
	}
}

