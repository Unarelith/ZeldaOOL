/*
 * =====================================================================================
 *
 *       Filename:  MovingState.hpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:25:00
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
		
		virtual bool canStartMapTransition() const override { return true; }
		
	protected:
		bool m_directionLocked = false;
};

#endif // MOVINGSTATE_HPP_
