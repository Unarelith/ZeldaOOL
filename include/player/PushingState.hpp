/*
 * =====================================================================================
 *
 *       Filename:  PushingState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 05:47:16
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
		
		void draw();
};

#endif // PUSHINGSTATE_HPP_
