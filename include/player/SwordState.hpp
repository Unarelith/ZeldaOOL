/*
 * =====================================================================================
 *
 *       Filename:  SwordState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:25:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SWORDSTATE_HPP_
#define SWORDSTATE_HPP_

#include "MovingState.hpp"
#include "Sword.hpp"

class SwordState : public MovingState {
	public:
		SwordState();
		~SwordState();
		
		void move(double dx, double dy);
		
		void movePlayer(u8 direction, bool forward = true);
		
		void update();
		
		void draw();
		void drawPlayer();
		
		bool canStartMapTransition() { return m_sword->state() == Sword::State::Loading; }
		
	private:
		bool m_playerMoved;
		
		Sword *m_sword;
};

#endif // SWORDSTATE_HPP_
