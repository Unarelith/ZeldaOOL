/*
 * =====================================================================================
 *
 *       Filename:  MovingState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 04:55:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef MOVINGSTATE_HPP_
#define MOVINGSTATE_HPP_

#include "PlayerState.hpp"

class MovingState : public PlayerState {
	public:
		MovingState();
		~MovingState();
		
		void move();
		
		virtual void update();
		
		virtual void draw();
};

#endif // MOVINGSTATE_HPP_
