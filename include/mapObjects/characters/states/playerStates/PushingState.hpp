/*
 * =====================================================================================
 *
 *       Filename:  PushingState.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:25:14
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PUSHINGSTATE_HPP_
#define PUSHINGSTATE_HPP_

#include "MovingState.hpp"

class PushingState : public MovingState {
	public:
		void update();
		
		void render();
};

#endif // PUSHINGSTATE_HPP_
