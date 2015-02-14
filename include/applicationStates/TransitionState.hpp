/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 10:42:21
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
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
		TransitionState(Transition *transition, ApplicationState *parent) : ApplicationState(parent), m_transition(transition) {}
		
		void update() override;
		
		void draw() override;
		
	private:
		std::unique_ptr<Transition> m_transition;
};

#endif // TRANSITIONSTATE_HPP_
