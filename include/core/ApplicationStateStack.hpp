/*
 * =====================================================================================
 *
 *       Filename:  ApplicationStateStack.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16/01/2015 00:49:39
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
		template<typename T, typename... Args>
		void push(Args &&...args) {
			m_states.push(std::make_shared<T>(std::forward<Args>(args)...));
			m_states.top()->setStateStack(this);
		}
		
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
