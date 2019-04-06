/*
 * =====================================================================================
 *
 *       Filename:  TransitionState.hpp
 *
 *    Description:
 *
 *        Created:  05/10/2014 17:42:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef TRANSITIONSTATE_HPP_
#define TRANSITIONSTATE_HPP_

#include <memory>

#include <gk/core/ApplicationState.hpp>

#include "StatsBar.hpp"
#include "Transition.hpp"

class TransitionState : public gk::ApplicationState {
	public:
		TransitionState(gk::ApplicationState *parent);

		void update() override;

		template<typename T, typename... Args>
		T &setTransition(Args &&...args) {
			m_transition.reset(new T(std::forward<Args>(args)...));
			return *static_cast<T*>(m_transition.get());
		}

	private:
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		StatsBar m_statsBar;

		std::unique_ptr<Transition> m_transition;
};

#endif // TRANSITIONSTATE_HPP_
