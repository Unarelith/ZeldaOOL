/*
 * =====================================================================================
 *
 *       Filename:  KeyboardHandler.cpp
 *
 *    Description:
 *
 *        Created:  11/02/2015 15:49:47
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/IntTypes.hpp>
#include <gk/core/XMLFile.hpp>
#include <gk/system/Debug.hpp>

#include "GameKey.hpp"
#include "KeyboardHandler.hpp"

KeyboardHandler::KeyboardHandler() {
	gk::XMLFile doc("resources/config/keys.xml");

	tinyxml2::XMLElement *keys = doc.FirstChildElement("keys").ToElement();

	// Reading keys from names as defined here: https://wiki.libsdl.org/SDL_Keycode
	auto addKey = [&](gk::GameKey key, const char *name) {
		tinyxml2::XMLElement *keyElement = keys->FirstChildElement(name);
		m_keys[key] = SDL_GetKeyFromName(keyElement->Attribute("key"));

		if(m_keys[key] == SDLK_UNKNOWN) {
			DEBUG("Key '", keyElement->Attribute("key"), "' not recognized");
		}
	};

	addKey(GameKey::Left,  "Left");
	addKey(GameKey::Right, "Right");
	addKey(GameKey::Up,    "Up");
	addKey(GameKey::Down,  "Down");

	addKey(GameKey::A, "A");
	addKey(GameKey::B, "B");

	addKey(GameKey::Start,  "Start");
	addKey(GameKey::Select, "Select");
}

bool KeyboardHandler::isKeyPressed(gk::GameKey key) {
	const u8 *keyboardState = SDL_GetKeyboardState(nullptr);
	SDL_Scancode keyScancode = SDL_GetScancodeFromKey(m_keys[key]);

	m_keysPressed[key] = keyboardState[keyScancode];

	return keyboardState[keyScancode];
}

