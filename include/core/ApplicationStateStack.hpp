/*
 * =====================================================================================
 *
 *       Filename:  ApplicationStateStack.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:45:47
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
		template<typename T, typename... Args>
		void push(Args &&...args) {
			m_states.push(std::make_shared<T>(std::forward<Args>(args)...));
		}
		
		void pop() { m_states.pop(); }
		
		ApplicationState *top() const { return m_states.top().get(); }
		
		std::size_t size() const { return m_states.size(); }
		
	private:
		std::stack<std::shared_ptr<ApplicationState>> m_states;
};

#endif // APPLICATIONSTATESTACK_HPP_
