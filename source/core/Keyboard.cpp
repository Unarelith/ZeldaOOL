/*
 * =====================================================================================
 *
 *       Filename:  Keyboard.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:42:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "SDLHeaders.hpp"
#include "TimeManager.hpp"

std::map<Keyboard::Key, bool> Keyboard::pressed = {
	{Key::Left,		false},
	{Key::Right,	false},
	{Key::Up,		false},
	{Key::Down,		false},
	
	{Key::A,		false},
	{Key::B,		false},
	
	{Key::Start,	false},
	{Key::Select,	false}
};

std::map<Keyboard::Key, u32> Keyboard::lastTimePressed = {
	{Key::Left,		0},
	{Key::Right,	0},
	{Key::Up,		0},
	{Key::Down,		0},
	
	{Key::A,		0},
	{Key::B,		0},
	
	{Key::Start,	0},
	{Key::Select,	0}
};

std::map<Keyboard::Key, u32> Keyboard::keysCode = {
	{Key::Left,		SDL_SCANCODE_LEFT},
	{Key::Right,	SDL_SCANCODE_RIGHT},
	{Key::Up,		SDL_SCANCODE_UP},
	{Key::Down,		SDL_SCANCODE_DOWN},
	
	{Key::A,		SDL_SCANCODE_W},
	{Key::B,		SDL_SCANCODE_X},
	
	{Key::Start,	SDL_SCANCODE_RETURN},
	{Key::Select,	SDL_SCANCODE_BACKSPACE}
};

const u8 *Keyboard::getState() {
	return SDL_GetKeyboardState(nullptr);
}

bool Keyboard::isKeyPressed(Key key) {
	if(getState()[keysCode[key]]) {
		return true;
	} else {
		return false;
	}
}

bool Keyboard::isKeyPressedOnce(Key key) {
	if(Keyboard::isKeyPressed(key)) {
		if(!pressed[key]) {
			pressed[key] = true;
			return true;
		} else {
			return false;
		}
	} else {
		pressed[key] = false;
		return false;
	}
}

bool Keyboard::isKeyPressedWithDelay(Key key, u16 delay) {
	if(Keyboard::isKeyPressed(key) && TimeManager::getTicks() - lastTimePressed[key] > delay) {
		lastTimePressed[key] = TimeManager::getTicks();
		return true;
	} else {
		if(!Keyboard::isKeyPressed(key)) {
			lastTimePressed[key] = 0;
		}
		
		return false;
	}
}

