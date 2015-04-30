/*
 * =====================================================================================
 *
 *       Filename:  ChestOpenedState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 00:58:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef CHESTOPENEDSTATE_HPP_
#define CHESTOPENEDSTATE_HPP_

#include "Collectable.hpp"
#include "ApplicationState.hpp"

class ChestOpenedState : public ApplicationState {
	public:
		ChestOpenedState(ApplicationState *parent, float x, float y, Collectable &collectable);
		
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

#endif // CHESTOPENEDSTATE_HPP_
