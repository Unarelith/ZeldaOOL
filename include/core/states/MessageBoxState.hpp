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
#include "SceneObject.hpp"

class MessageBoxState : public ApplicationState {
	public:
		MessageBoxState(SceneObject &player, const std::string &text, ApplicationState *parent);

		void update() override;

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		MessageBox m_messageBox;
};

#endif // MESSAGEBOXSTATE_HPP_
