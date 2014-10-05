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

#include "GameStateManager.hpp"
#include "Transition.hpp"

class TransitionState : public GameState {
	public:
		TransitionState(Transition *transition);
		~TransitionState();
		
		void update();
		
		void render();
		
	private:
		Transition *m_transition;
};

#endif // TRANSITIONSTATE_HPP_
