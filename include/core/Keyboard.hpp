/*
 * =====================================================================================
 *
 *       Filename:  Keyboard.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:41:56
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <map>

#include "Types.hpp"

namespace Keyboard {
	enum Key {
		Left,
		Right,
		Up,
		Down,
		
		A,
		B,
		
		Start,
		Select
	};
	
	const u8 *getState();
	
	bool isKeyPressed(Key key);
	bool isKeyPressedOnce(Key key);
	bool isKeyPressedWithDelay(Key key, u16 delay);
	
	extern std::map<Key, bool> pressed;
	extern std::map<Key, u32> lastTimePressed;
	extern std::map<Key, u32> keysCode;
}

#endif // KEYBOARD_HPP_
