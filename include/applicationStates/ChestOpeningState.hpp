/*
 * =====================================================================================
 *
 *       Filename:  ChestOpeningState.hpp
 *
 *    Description:  
 *
 *        Created:  24/02/2015 15:43:52
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHESTOPENINGSTATE_HPP_
#define CHESTOPENINGSTATE_HPP_

#include "ApplicationState.hpp"

class ChestOpeningState : public ApplicationState {
	public:
		ChestOpeningState(ApplicationState *parent);
		
		void update() override;
		
		void draw() override;
		
		enum class State {
			Opening,
			Opened,
			Finished
		};
		
	private:
		State m_state = State::Opened;
};

#endif // CHESTOPENINGSTATE_HPP_
