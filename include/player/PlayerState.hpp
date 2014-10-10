/*
 * =====================================================================================
 *
 *       Filename:  PlayerState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:24:24
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
		
		virtual void move(double dx, double dy);
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
		virtual bool canStartMapTransition() { return false; }
		
		enum StateType {
			TypeHurt,
			TypeMoving,
			TypePushing,
			TypeStanding,
			TypeSword
		};
		
		StateType stateType() const { return m_stateType; };
		
		StateType nextStateType() const { return m_nextStateType; };
		void setNextStateType(StateType nextStateType) { m_nextStateType = nextStateType; }
		void resetNextStateType() { m_nextStateType = m_stateType; }
		
		PlayerState *nextState();
		
	protected:
		Player &m_player;
		
		StateType m_stateType;
		StateType m_nextStateType;
};

#include "CharacterManager.hpp"

#endif // PLAYERSTATE_HPP_
