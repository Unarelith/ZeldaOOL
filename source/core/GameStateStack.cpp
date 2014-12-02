/*
 * =====================================================================================
 *
 *       Filename:  GameStateStack.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:09:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GameStateStack.hpp"
#include "MapState.hpp"

GameStateStack::GameStateStack() {
	push(new MapState);
}

GameStateStack::~GameStateStack() {
}

GameStateStack &GameStateStack::getInstance() {
	static GameStateStack instance;
	return instance;
}

