/*
 * =====================================================================================
 *
 *       Filename:  GameState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:16:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

class GameState {
	public:
		GameState(GameState *parent = nullptr);
		virtual ~GameState();
		
		virtual void update() = 0;
		
		virtual void render() = 0;
		
	protected:
		GameState *m_parent;
};

#endif // GAMESTATE_HPP_
