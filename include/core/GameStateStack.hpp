/*
 * =====================================================================================
 *
 *       Filename:  GameStateStack.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:08:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GAMESTATESTACK_HPP_
#define GAMESTATESTACK_HPP_

#include <memory>
#include <stack>

#include "GameState.hpp"

class GameStateStack {
	public:
		GameStateStack();
		~GameStateStack();
		
		GameState &top() { return *m_stack.top().get(); } 
		void push(GameState *state) { m_stack.push(std::unique_ptr<GameState>(state)); }
		void pop() { m_stack.pop(); }
		
		static GameStateStack &getInstance();
		
	private:
		std::stack<std::unique_ptr<GameState>> m_stack;
};

#endif // GAMESTATESTACK_HPP_
