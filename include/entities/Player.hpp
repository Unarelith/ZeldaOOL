/*
 * =====================================================================================
 *
 *       Filename:  Player.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:17:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Character.hpp"
#include "PlayerState.hpp"

class Player : public Character {
	public:
		Player();
		~Player();
		
		void mapCollisions();
		
		void update();
		
		void draw();
		
		void setNextStateType(PlayerState::StateType nextType);
		
		PlayerState *currentState() const { return m_state; }
		
		u8 maxLife() const { return m_maxLife; }
		u8 life() const { return m_life; }
		
		u16 rupees() const { return m_rupees; }
		
	private:
		PlayerState *m_state;
		
		u8 m_maxLife;
		u8 m_life;
		
		u16 m_rupees;
};

#endif // PLAYER_HPP_