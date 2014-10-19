/*
 * =====================================================================================
 *
 *       Filename:  HurtState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/2014 22:59:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef HURTSTATE_HPP_
#define HURTSTATE_HPP_

#include "BattlerState.hpp"
#include "HurtMovement.hpp"

class HurtState : public BattlerState {
	public:
		HurtState(Battler *battler);
		~HurtState();
		
		void update();
		
		void draw();
		
	private:
		Movement *m_movement;
};

#endif // HURTSTATE_HPP_
