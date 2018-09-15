/*
 * =====================================================================================
 *
 *       Filename:  ApplicationState.hpp
 *
 *    Description:
 *
 *        Created:  15/09/2014 00:16:41
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef APPLICATIONSTATE_HPP_
#define APPLICATIONSTATE_HPP_

#include "SDLHeaders.hpp"

class ApplicationStateStack;

class ApplicationState {
	public:
		ApplicationState(ApplicationState *parent = nullptr) : m_parent(parent) {}
		ApplicationState(const ApplicationState &) = delete;
		ApplicationState(ApplicationState &&) = default;
		virtual ~ApplicationState() = default;

		ApplicationState &operator=(const ApplicationState &) = delete;
		ApplicationState &operator=(ApplicationState &&) = default;

		virtual void onEvent(SDL_Event &) {}

		virtual void update() = 0;
		virtual void draw() = 0;

		void setStateStack(ApplicationStateStack *stateStack) { m_stateStack = stateStack; }

	protected:
		ApplicationState *m_parent = nullptr;

		ApplicationStateStack *m_stateStack = nullptr;
};

#endif // APPLICATIONSTATE_HPP_
