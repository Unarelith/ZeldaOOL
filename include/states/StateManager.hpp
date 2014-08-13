/*
 * =====================================================================================
 *
 *       Filename:  StateManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 13:54:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

#include <stack>

#include "Types.hpp"
#include "State.hpp"

namespace StateManager {
	void init();
	void free();
	
	extern std::stack<State*> states;
	
	State *top();
	void pop();
	void push(State *state);
	u16 size();
};

#endif // STATEMANAGER_HPP_
