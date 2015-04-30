/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.hpp
 *
 *    Description:  
 *
 *        Created:  05/10/2014 17:42:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TRANSITIONSTATE_HPP_
#define TRANSITIONSTATE_HPP_

#include <memory>

#include "ApplicationState.hpp"
#include "Transition.hpp"

class TransitionState : public ApplicationState {
	public:
		TransitionState(Transition *transition) : m_transition(transition) {}
		
		void update();
		
		void draw();
		
	private:
		std::unique_ptr<Transition> m_transition;
};

#endif // TRANSITIONSTATE_HPP_
