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

#include "PlayerState.hpp"

class HurtState : public PlayerState {
	public:
		HurtState(s16 vx, s16 vy, float speed);
		
		void update();
		
		void render();
};

#endif // HURTSTATE_HPP_
