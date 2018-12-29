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

#include <gk/core/ApplicationState.hpp>

#include "MessageBox.hpp"

class MessageBoxState : public gk::ApplicationState {
	public:
		MessageBoxState(const std::string &text, gk::ApplicationState *parent);

		void update() override;

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		MessageBox m_messageBox;
};

#endif // MESSAGEBOXSTATE_HPP_
