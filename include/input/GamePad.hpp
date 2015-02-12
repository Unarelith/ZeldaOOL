/*
 * =====================================================================================
 *
 *       Filename:  GamePad.hpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:49:25
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include <map>
#include <memory>

#include "InputHandler.hpp"

class GamePad {
	public:
		static void init(InputHandler &_inputHandler) { inputHandler = &_inputHandler; }
		
		static bool isKeyPressed(GameKey key);
		static bool isKeyPressedOnce(GameKey key);
		
	private:
		static InputHandler *inputHandler;
		
		static std::map<GameKey, bool> keysPressed;
};

#endif // GAMEPAD_HPP_
