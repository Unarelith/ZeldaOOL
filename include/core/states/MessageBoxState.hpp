/*
 * =====================================================================================
 *
 *       Filename:  MessageBoxState.hpp
 *
 *    Description:
 *
 *        Created:  23/02/2015 16:52:36
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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

		void update() override;

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		MessageBox m_messageBox;
};

#endif // MESSAGEBOXSTATE_HPP_
