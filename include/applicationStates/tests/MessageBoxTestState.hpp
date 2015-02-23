/*
 * =====================================================================================
 *
 *       Filename:  MessageBoxTestState.hpp
 *
 *    Description:  
 *
 *        Created:  22/02/2015 17:50:43
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MESSAGEBOXTESTSTATE_HPP_
#define MESSAGEBOXTESTSTATE_HPP_

#include "ApplicationState.hpp"
#include "Font.hpp"

class MessageBoxTestState : public ApplicationState {
	public:
		MessageBoxTestState();
		~MessageBoxTestState();
		
		void update() override;
		
		void draw() override;
		
	private:
		Font m_font{"interface-font", 8, 16};
};

#endif // MESSAGEBOXTESTSTATE_HPP_
