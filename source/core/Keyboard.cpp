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
#include "GameClock.hpp"
#include "Keyboard.hpp"
#include "SDLHeaders.hpp"

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
	{Key::Left,		SDLK_LEFT},
	{Key::Right,	SDLK_RIGHT},
	{Key::Up,		SDLK_UP},
	{Key::Down,		SDLK_DOWN},
	
	{Key::A,		SDLK_x},
	{Key::B,		SDLK_w},
	
	{Key::Start,	SDLK_RETURN},
	{Key::Select,	SDLK_BACKSPACE}
};

const u8 *Keyboard::getState() {
	return SDL_GetKeyboardState(nullptr);
}

bool Keyboard::isKeyPressed(Key key) {
	if(getState()[SDL_GetScancodeFromKey(keysCode[key])]) {
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
	if(Keyboard::isKeyPressed(key) && GameClock::getTicks() - lastTimePressed[key] > delay) {
		lastTimePressed[key] = GameClock::getTicks();
		return true;
	} else {
		if(!Keyboard::isKeyPressed(key)) {
			lastTimePressed[key] = 0;
		}
		
		return false;
	}
}

