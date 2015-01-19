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
 *        Company:  
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
