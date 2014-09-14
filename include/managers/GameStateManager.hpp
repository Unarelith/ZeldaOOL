/*
 * =====================================================================================
 *
 *       Filename:  GameStateManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:18:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef GAMESTATEMANAGER_HPP_
#define GAMESTATEMANAGER_HPP_

#include <stack>

#include "GameState.hpp"
#include "Types.hpp"

namespace GameStateManager {
	void init();
	void free();
	
	extern std::stack<GameState*> states;
	
	GameState *top();
	void pop();
	void push(GameState *state);
	u16 size();
}

#endif // GAMESTATEMANAGER_HPP_
