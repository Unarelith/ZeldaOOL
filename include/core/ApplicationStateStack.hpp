/*
 * =====================================================================================
 *
 *       Filename:  ApplicationStateStack.hpp
 *
 *    Description:
 *
 *        Created:  16/01/2015 00:49:39
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
			m_states.push(std::make_shared<T>(std::forward<Args>(args)...));
			m_states.top()->setStateStack(this);
			return *static_cast<T*>(top());
		}

		// WARNING: When you use this function, make sure that you're
		// not reading/writing anything from/to the deleted objects
		void pop() { m_states.pop(); }

		ApplicationState *top() const { return m_states.top().get(); }

		std::size_t size() const { return m_states.size(); }

		// FIXME: To remove. Used in NPC (DialogState), ChestObject (ChestOpenedState) and DoorObject (TransitionState).
		static ApplicationStateStack &getInstance() {
			static ApplicationStateStack instance;
			return instance;
		}

	private:
		ApplicationStateStack() = default;

		std::stack<std::shared_ptr<ApplicationState>> m_states;
};

#endif // APPLICATIONSTATESTACK_HPP_
