/*
 * =====================================================================================
 *
 *       Filename:  GamePad.cpp
 *
 *    Description:  
 *
 *        Created:  11/02/2015 15:49:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
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

