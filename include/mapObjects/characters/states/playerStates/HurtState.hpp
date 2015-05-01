/*
 * =====================================================================================
 *
 *       Filename:  HurtState.hpp
 *
 *    Description:  
 *
 *        Created:  09/10/2014 22:59:33
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
