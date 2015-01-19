/*
 * =====================================================================================
 *
 *       Filename:  ApplicationState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 00:16:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef APPLICATIONSTATE_HPP_
#define APPLICATIONSTATE_HPP_

class ApplicationStateStack;

class ApplicationState {
	public:
		ApplicationState(ApplicationState *parent = nullptr) : m_parent(parent) {}
		ApplicationState(const ApplicationState &) = delete;
		ApplicationState(ApplicationState &&) = default;
		
		void setStackHandle(ApplicationStateStack *stateStack) { m_stateStack = stateStack; }
		
		virtual void update() = 0;
		
		virtual void render() = 0;
		
	protected:
		ApplicationState *m_parent = nullptr;
		
		ApplicationStateStack *m_stateStack = nullptr;
};

#include "ApplicationStateStack.hpp"

#endif // APPLICATIONSTATE_HPP_
