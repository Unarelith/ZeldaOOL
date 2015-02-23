/*
 * =====================================================================================
 *
 *       Filename:  ApplicationStateStack.hpp
 *
 *    Description:  
 *
 *        Created:  08/02/2015 22:45:47
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
		T &push(Args &&...args) {
			m_states.emplace(new T(std::forward<Args>(args)...));
			return *static_cast<T*>(top());
		}
		
		// WARNING: When you use this function, make sure that you're
		// not reading/writing anything from/to the deleted objects
		void pop() { m_states.pop(); }
		
		ApplicationState *top() const { return m_states.top().get(); }
		
		std::size_t size() const { return m_states.size(); }
		
		static ApplicationStateStack &getInstance() {
			static ApplicationStateStack instance;
			return instance;
		}
		
	private:
		ApplicationStateStack() = default;
		
		std::stack<std::unique_ptr<ApplicationState>> m_states;
};

#endif // APPLICATIONSTATESTACK_HPP_
