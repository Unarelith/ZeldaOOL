/*
 * =====================================================================================
 *
 *       Filename:  TestState.hpp
 *
 *    Description:  
 *
 *        Created:  12/02/2015 20:06:08
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TESTSTATE_HPP_
#define TESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "Font.hpp"

class TestState : public ApplicationState {
	public:
		void update() override;
		
		void draw() override;
		
	private:
		Font m_font{"interface-font", 8, 16};
};

#endif // TESTSTATE_HPP_
