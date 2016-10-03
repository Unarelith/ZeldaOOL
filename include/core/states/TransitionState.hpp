/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.hpp
 *
 *    Description:
 *
 *        Created:  05/10/2014 17:42:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TRANSITIONSTATE_HPP_
#define TRANSITIONSTATE_HPP_

#include <memory>

#include "ApplicationState.hpp"
#include "StatsBar.hpp"
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
		StatsBar m_statsBar;

		std::unique_ptr<Transition> m_transition;
};

#endif // TRANSITIONSTATE_HPP_
