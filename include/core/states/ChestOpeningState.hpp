/*
 * =====================================================================================
 *
 *       Filename:  ChestOpeningState.hpp
 *
 *    Description:  
 *
 *        Created:  07/10/2014 00:58:17
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHESTOPENINGSTATE_HPP_
#define CHESTOPENINGSTATE_HPP_

#include "Collectable.hpp"
#include "ApplicationState.hpp"

class ChestOpeningState : public ApplicationState {
	public:
		ChestOpeningState(ApplicationState *parent, float x, float y, Collectable &collectable);
		
		void update();
		
		void draw();
		
		enum State {
			Opening,
			Opened,
			Finished
		};
		
	private:
		State m_state = State::Opening;
		
		Collectable *m_collectable = nullptr;
		
		float m_movementCounter = 0;
		
		float m_speed = 0.125f;
};

#endif // CHESTOPENINGSTATE_HPP_
