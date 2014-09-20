/*
 * =====================================================================================
 *
 *       Filename:  GameStateManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:19:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "GameStateManager.hpp"
#include "MapState.hpp"

std::stack<GameState*> GameStateManager::states;

void GameStateManager::init() {
	push(new MapState());
}

void GameStateManager::free() {
	while(size() != 0) {
		pop();
	}
}

GameState *GameStateManager::top() {
	return states.top();
}

void GameStateManager::pop() {
	delete top();
	states.pop();
}

void GameStateManager::push(GameState *state) {
	states.push(state);
}

u16 GameStateManager::size() {
	return states.size();
}

