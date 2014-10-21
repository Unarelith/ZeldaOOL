/*
 * =====================================================================================
 *
 *       Filename:  PushingState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:25:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef PUSHINGSTATE_HPP_
#define PUSHINGSTATE_HPP_

#include "MovingState.hpp"

class PushingState : public MovingState {
	public:
		PushingState();
		~PushingState();
		
		void update();
		
		void render();
};

#endif // PUSHINGSTATE_HPP_
