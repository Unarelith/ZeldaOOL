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
#include "MessageBox.hpp"

class MessageBoxTestState : public ApplicationState {
	public:
		MessageBoxTestState();
		
		void update() override;
		
		void draw() override;
		
	private:
		MessageBox m_messageBox;
};

#endif // MESSAGEBOXTESTSTATE_HPP_
