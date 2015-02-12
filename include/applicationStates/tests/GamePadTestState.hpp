/*
 * =====================================================================================
 *
 *       Filename:  GamePadTestState.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 17:45:59
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GAMEPADTESTSTATE_HPP_
#define GAMEPADTESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "Font.hpp"

class GamePadTestState : public ApplicationState {
	public:
		void update() override;
		
		void draw() override;
		
	private:
		Font m_font{"interface-font", 8, 16};
};

#endif // GAMEPADTESTSTATE_HPP_
