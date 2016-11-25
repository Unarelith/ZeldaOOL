/*
 * =====================================================================================
 *
 *       Filename:  GamePad.hpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 13:46:23
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef GAMEPAD_HPP_
#define GAMEPAD_HPP_

#include <map>
#include <memory>

#include "InputHandler.hpp"
#include "IntTypes.hpp"

class GamePad {
	public:
		static void init(InputHandler &_inputHandler) { inputHandler = &_inputHandler; }

		static bool isKeyPressed(GameKey key);
		static bool isKeyPressedOnce(GameKey key);
		static bool isKeyPressedWithDelay(GameKey key, u16 delay);

	private:
		static InputHandler *inputHandler;

		static std::map<GameKey, bool> keysPressed;
		static std::map<GameKey, u32> lastTimePressed;

		// Lock to avoid bugs when opposite keys are pressed
		static bool m_verticalLock, m_horizontalLock;
		static GameKey m_verticalValue, m_horizontalValue;
};

#endif // GAMEPAD_HPP_
