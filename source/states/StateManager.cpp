/*
 * =====================================================================================
 *
 *       Filename:  StateManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 13:54:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "MapState.hpp"
#include "StateManager.hpp"

std::stack<State*> StateManager::states;

void StateManager::init() {
	push(new MapState());
}

void StateManager::free() {
	while(size() != 0) {
		pop();
	}
}

State *StateManager::top() {
	return states.top();
}

void StateManager::pop() {
	delete top();
	states.pop();
}

void StateManager::push(State *state) {
	states.push(state);
}

u16 StateManager::size() {
	return states.size();
}

