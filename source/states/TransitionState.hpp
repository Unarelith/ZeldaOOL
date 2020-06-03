/*
 * =====================================================================================
 *
 *  ZeldaOOL
 *
 *  Copyright (C) 2014-2020 Unarelith, Quentin Bazin <zelda.ool@unarelith.net>
 *
 *  This file is part of ZeldaOOL.
 *
 *  ZeldaOOL is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  ZeldaOOL is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with ZeldaOOL; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
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
		void draw(gk::RenderTarget &target, gk::RenderStates states) const override;

		StatsBar m_statsBar;

		std::unique_ptr<Transition> m_transition;
};

#endif // TRANSITIONSTATE_HPP_
