/*
 * =====================================================================================
 *
 *       Filename:  StandingState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 04:50:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef STANDINGSTATE_HPP_
#define STANDINGSTATE_HPP_

#include "PlayerState.hpp"

class StandingState : public PlayerState {
	public:
		StandingState();
		~StandingState();
		
		void update();
		
		void draw();
};

#endif // STANDINGSTATE_HPP_
