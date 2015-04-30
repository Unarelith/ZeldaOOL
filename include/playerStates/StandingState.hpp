/*
 * =====================================================================================
 *
 *       Filename:  StandingState.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:24:47
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef STANDINGSTATE_HPP_
#define STANDINGSTATE_HPP_

#include "PlayerState.hpp"

class StandingState : public PlayerState {
	public:
		void update();
		
		void render();
};

#endif // STANDINGSTATE_HPP_
