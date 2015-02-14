/*
 * =====================================================================================
 *
 *       Filename:  TransitionTestState.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 10:35:24
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TRANSITIONTESTSTATE_HPP_
#define TRANSITIONTESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "Font.hpp"

class TransitionTestState : public ApplicationState {
	public:
		TransitionTestState();
		
		void update() override;
		
		void draw() override;
		
		enum class Mode {
			Menu,
			Scrolling,
			Door
		};
		
	private:
		Mode m_mode = Mode::Menu;
		
		Font m_font{"interface-font", 8, 16};
};

#endif // TRANSITIONTESTSTATE_HPP_
