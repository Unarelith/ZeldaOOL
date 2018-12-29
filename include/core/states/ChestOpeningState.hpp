/*
 * =====================================================================================
 *
 *       Filename:  ChestOpeningState.hpp
 *
 *    Description:
 *
 *        Created:  07/10/2014 00:58:17
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef CHESTOPENINGSTATE_HPP_
#define CHESTOPENINGSTATE_HPP_

#include <gk/core/ApplicationState.hpp>

#include "SceneObject.hpp"

class ChestOpeningState : public gk::ApplicationState {
	public:
		ChestOpeningState(SceneObject &chest, gk::ApplicationState *parent);

		void update() override;

		enum class State {
			Opening,
			Opened,
			Finished
		};

	private:
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		State m_state = State::Opening;

		SceneObject *m_item = nullptr;
};

#endif // CHESTOPENINGSTATE_HPP_
