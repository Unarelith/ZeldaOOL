/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.cpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:49:47
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "IntTypes.hpp"
#include "KeyboardHandler.hpp"

bool KeyboardHandler::isKeyPressed(GameKey key) {
	const u8 *keyboardState = SDL_GetKeyboardState(nullptr);
	SDL_Scancode keyScancode = SDL_GetScancodeFromKey(m_keys[key]);
	
	return keyboardState[keyScancode];
}

