/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.hpp
 *
 *    Description:
 *
 *        Created:  11/02/2015 15:49:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef KEYBOARDHANDLER_HPP_
#define KEYBOARDHANDLER_HPP_

#include <map>

#include "InputHandler.hpp"
#include "SDLHeaders.hpp"

class KeyboardHandler : public InputHandler {
	public:
		bool isKeyPressed(GameKey key);

	private:
		std::map<GameKey, SDL_Keycode> m_keys{
			{GameKey::Left,     SDLK_LEFT},
			{GameKey::Right,    SDLK_RIGHT},
			{GameKey::Up,       SDLK_UP},
			{GameKey::Down,     SDLK_DOWN},

			{GameKey::A,        SDLK_x},
			{GameKey::B,        SDLK_w},

			{GameKey::Start,    SDLK_RETURN},
			{GameKey::Select,   SDLK_BACKSPACE}
		};
};

#endif // KEYBOARDHANDLER_HPP_
