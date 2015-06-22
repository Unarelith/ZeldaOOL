/*
 * =====================================================================================
 *
 *       Filename:  MessageBoxState.hpp
 *
 *    Description:  
 *
 *        Created:  23/02/2015 16:52:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MESSAGEBOXSTATE_HPP_
#define MESSAGEBOXSTATE_HPP_

#include "ApplicationState.hpp"
#include "MessageBox.hpp"

class MessageBoxState : public ApplicationState {
	public:
		MessageBoxState(const std::string &text, ApplicationState *parent);
		
		void update();
		
		void draw();
		
	private:
		MessageBox m_messageBox;
};

#endif // MESSAGEBOXSTATE_HPP_
