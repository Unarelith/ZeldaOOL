/*
 * =====================================================================================
 *
 *       Filename:  MovingState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:25:00
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
		virtual void update();
		
		virtual void render();
		
		virtual bool canStartMapTransition() { return true; }
		
	protected:
		bool m_directionLocked = false;
};

#endif // MOVINGSTATE_HPP_
