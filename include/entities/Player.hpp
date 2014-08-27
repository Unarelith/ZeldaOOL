/*
 * =====================================================================================
 *
 *       Filename:  Player.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/08/2014 19:11:30
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

class Player : public Character {
	public:
		Player();
		~Player();
		
		void mapCollisions();
		
		void move();
		
		void update();
		
		void draw();
		
		u8 maxLife() const { return m_maxLife; }
		u8 life() const { return m_life; }
		
		u16 rupees() const { return m_rupees; }
		
	private:
		State *m_currentState;
		
		u8 m_maxLife;
		u8 m_life;
		
		u16 m_rupees;
};

#endif // PLAYER_HPP_
