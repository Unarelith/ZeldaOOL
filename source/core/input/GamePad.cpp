/*
 * =====================================================================================
 *
 *       Filename:  GamePad.cpp
 *
 *    Description:
 *
 *        Created:  01/05/2015 13:46:38
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "GameClock.hpp"
#include "GamePad.hpp"

InputHandler *GamePad::inputHandler = nullptr;

std::map<GameKey, bool> GamePad::keysPressed = {
	{GameKey::Left,   false},
	{GameKey::Right,  false},
	{GameKey::Up,     false},
	{GameKey::Down,   false},

	{GameKey::A,      false},
	{GameKey::B,      false},

	{GameKey::Start,  false},
	{GameKey::Select, false}
};

std::map<GameKey, u32> GamePad::lastTimePressed = {
	{GameKey::Left,     0},
	{GameKey::Right,    0},
	{GameKey::Up,       0},
	{GameKey::Down,     0},

	{GameKey::A,        0},
	{GameKey::B,        0},

	{GameKey::Start,    0},
	{GameKey::Select,   0}
};

bool GamePad::isKeyPressed(GameKey key) {
	return (inputHandler) ? inputHandler->isKeyPressed(key) : false;
}

bool GamePad::isKeyPressedOnce(GameKey key) {
	if(GamePad::isKeyPressed(key)) {
		if(!keysPressed[key]) {
			keysPressed[key] = true;
			return true;
		} else {
			return false;
		}
	} else {
		keysPressed[key] = false;
		return false;
	}
}

bool GamePad::isKeyPressedWithDelay(GameKey key, u16 delay) {
	if(GamePad::isKeyPressed(key) && GameClock::getTicks() - lastTimePressed[key] > delay) {
		lastTimePressed[key] = GameClock::getTicks();
		return true;
	} else {
		if(!GamePad::isKeyPressed(key)) lastTimePressed[key] = 0;
		return false;
	}
}

