/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 10:42:21
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef TRANSITIONSTATE_HPP_
#define TRANSITIONSTATE_HPP_

#include <memory>

#include "ApplicationState.hpp"
#include "Transition.hpp"

class TransitionState : public ApplicationState {
	public:
		TransitionState(ApplicationState *parent) : ApplicationState(parent) {}
		
		void update() override;
		
		void draw() override;
		
		template<typename T, typename... Args>
		T &setTransition(Args &&...args) {
			m_transition.reset(new T(std::forward<Args>(args)...));
			return *static_cast<T*>(m_transition.get());
		}
		
	private:
		std::unique_ptr<Transition> m_transition;
};

#endif // TRANSITIONSTATE_HPP_
