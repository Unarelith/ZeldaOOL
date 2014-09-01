/*
 * =====================================================================================
 *
 *       Filename:  SwordState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 16:15:43
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

#include "Keyboard.hpp"
#include "PlayerState.hpp"

class SwordState : public PlayerState {
	public:
		SwordState();
		~SwordState();
		
		void update();
		
		void draw();
		void drawPlayer();
		void drawSword();
		
	private:
		Sprite m_sword;
		
		u8 m_tmpDirection;
		
		Timer m_timer;
		bool m_spinAttack;
};

#endif // SWORDSTATE_HPP_
