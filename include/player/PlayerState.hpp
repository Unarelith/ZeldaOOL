/*
 * =====================================================================================
 *
 *       Filename:  PlayerState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 04:46:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef PLAYERSTATE_HPP_
#define PLAYERSTATE_HPP_

class Player;

class PlayerState {
	public:
		PlayerState();
		virtual ~PlayerState();
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
		PlayerState *nextState() const { return m_nextState; };
		void setNextState(PlayerState *nextState) { m_nextState = nextState; }
		
	protected:
		Player &m_player;
		
		PlayerState *m_nextState;
};

#include "CharacterManager.hpp"

#endif // PLAYERSTATE_HPP_
