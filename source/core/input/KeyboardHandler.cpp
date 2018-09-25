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
#include "Debug.hpp"
#include "IntTypes.hpp"
#include "KeyboardHandler.hpp"
#include "XMLFile.hpp"

KeyboardHandler::KeyboardHandler() {
	XMLFile doc("resources/config/keys.xml");

	XMLElement *keys = doc.FirstChildElement("keys").ToElement();

	// Reading keys from names as defined here: https://wiki.libsdl.org/SDL_Keycode
	auto addKey = [&](GameKey key, const char *name) {
		XMLElement *keyElement = keys->FirstChildElement(name);
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

bool KeyboardHandler::isKeyPressed(GameKey key) {
	const u8 *keyboardState = SDL_GetKeyboardState(nullptr);
	SDL_Scancode keyScancode = SDL_GetScancodeFromKey(m_keys[key]);

	return keyboardState[keyScancode];
}

