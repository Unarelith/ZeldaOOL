/*
 * =====================================================================================
 *
 *       Filename:  ApplicationStateStack.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2014 21:08:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef APPLICATIONSTATESTACK_HPP_
#define APPLICATIONSTATESTACK_HPP_

#include <memory>
#include <stack>

#include "ApplicationState.hpp"

class ApplicationStateStack {
	public:
		ApplicationStateStack();
		~ApplicationStateStack();
		
		ApplicationState &top() { return *m_stack.top().get(); } 
		void push(ApplicationState *state) { m_stack.push(std::unique_ptr<ApplicationState>(state)); }
		void pop() { m_stack.pop(); }
		
		static ApplicationStateStack &getInstance();
		
	private:
		std::stack<std::unique_ptr<ApplicationState>> m_stack;
};

#endif // APPLICATIONSTATESTACK_HPP_
