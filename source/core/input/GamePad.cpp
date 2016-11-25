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

bool GamePad::m_verticalLock = false;
bool GamePad::m_horizontalLock = false;

GameKey GamePad::m_verticalValue = GameKey::Down;
GameKey GamePad::m_horizontalValue = GameKey::Left;

bool GamePad::isKeyPressed(GameKey key) {
	if(!inputHandler) return false;

	if(key == GameKey::Up) { // First vertical key pressed disable the other one
		if (m_verticalLock && m_verticalValue == GameKey::Down) {
			return false;
		} else if(inputHandler->isKeyPressed(key)) {
			m_verticalLock = true;
			m_verticalValue = GameKey::Up;
			return true;
		} else {
			m_verticalLock = false;
			return false;
		}
	} else if(key == GameKey::Down) {
		if (m_verticalLock && m_verticalValue == GameKey::Up) {
			return false;
		} else if(inputHandler->isKeyPressed(key)) {
			m_verticalLock = true;
			m_verticalValue = GameKey::Down;
			return true;
		} else {
			m_verticalLock = false;
			return false;
		}
	} else if(key == GameKey::Left) { // First horizontal key pressed disable the other one
		if(m_horizontalLock && m_horizontalValue == GameKey::Right) {
			return false;
		} else if(inputHandler->isKeyPressed(key)) {
			m_horizontalLock = true;
			m_horizontalValue = GameKey::Left;
			return true;
		} else {
			m_horizontalLock = false;
			return false;
		}
	} else if(key == GameKey::Right) {
		if(m_horizontalLock && m_horizontalValue == GameKey::Left) {
			return false;
		} else if(inputHandler->isKeyPressed(key)) {
			m_horizontalLock = true;
			m_horizontalValue = GameKey::Right;
			return true;
		} else {
			m_horizontalLock = false;
			return false;
		}
	} else {
		return inputHandler->isKeyPressed(key);
	}
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

