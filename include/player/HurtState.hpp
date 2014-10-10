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

#include "MovingState.hpp"

class HurtState : public MovingState {
	public:
		HurtState();
		~HurtState();
		
		void update();
		
		void draw();
		
		enum State {
			MoveBack,
			CanMove
		};
		
	private:
		State m_state;
		
		Timer m_timer;
		
		float m_movementCounter;
};

#endif // HURTSTATE_HPP_
