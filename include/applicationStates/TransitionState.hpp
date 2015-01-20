/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2014 17:42:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
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
		TransitionState(Transition *transition) : m_transition(transition) {}
		
		void update();
		
		void render();
		
	private:
		std::unique_ptr<Transition> m_transition;
};

#endif // TRANSITIONSTATE_HPP_
