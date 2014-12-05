/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2014 01:07:46
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
		TransitionState(Transition *transition);
		~TransitionState();
		
		void update();
		
		void draw();
		
	private:
		std::unique_ptr<Transition> m_transition;
};

#endif // TRANSITIONSTATE_HPP_
