/*
 * =====================================================================================
 *
 *       Filename:  GameState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:21:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GameState.hpp"
#include "GameStateStack.hpp"

GameState::GameState() {
	
}

GameState::~GameState() {
}

GameStateStack &GameState::getGameStateStack() {
	return GameStateStack::getInstance();
}

