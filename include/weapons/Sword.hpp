/*
 * =====================================================================================
 *
 *       Filename:  Sword.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/09/2014 19:52:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef SWORD_HPP_
#define SWORD_HPP_

#include "Weapon.hpp"

class Sword : public Weapon {
	public:
		Sword();
		~Sword();
		
		void update();
		
		void draw();
		
		enum State {
			Swinging,
			Loading,
			Tapping,
			SpinAttack
		}
		
	private:
		State m_state;
};

#endif // SWORD_HPP_
