/*
 * =====================================================================================
 *
 *       Filename:  GameState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:21:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

// Avoid cyclic inclusion
class GameStateStack;

class GameState {
	public:
		GameState();
		virtual ~GameState();
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
		GameStateStack &getGameStateStack();
};

#endif // GAMESTATE_HPP_
