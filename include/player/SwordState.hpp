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

#include "Sword.hpp"
#include "MovingState.hpp"

class SwordState : public MovingState {
	public:
		SwordState();
		~SwordState();
		
		void update();
		
		void draw();
		void drawPlayer();
		
	private:
		Sword m_sword;
};

#endif // SWORDSTATE_HPP_
