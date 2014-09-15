/*
 * =====================================================================================
 *
 *       Filename:  StandingState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:24:47
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
