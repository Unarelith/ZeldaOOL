/*
 * =====================================================================================
 *
 *       Filename:  Keyboard.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/08/2014 12:34:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "TimeManager.hpp"
#include "Keyboard.hpp"

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

bool Keyboard::isKeyPressed(Key key) {
	return sf::Keyboard::isKeyPressed((sf::Keyboard::Key)key);
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

