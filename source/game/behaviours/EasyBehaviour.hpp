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
#ifndef EASYBEHAVIOUR_HPP_
#define EASYBEHAVIOUR_HPP_

#include <functional>

#include "Behaviour.hpp"

class EasyBehaviour : public Behaviour {
	using Action = std::function<void(gk::SceneObject&)>;

	public:
		enum class FunctionType {
			Action,
			Reset
		};

		EasyBehaviour(Action action, Action reset) : m_action(action), m_reset(reset) {}
		EasyBehaviour(Action action, FunctionType type = FunctionType::Action) {
			if(type == FunctionType::Action) {
				m_action = action;
			} else {
				m_reset = action;
			}
		}

		void reset(gk::SceneObject &object) override {
			if(m_reset) m_reset(object);
		}

		void update(gk::SceneObject &object) override {
			if(m_action) m_action(object);
		}

	private:
		Action m_action;

		Action m_reset;
};

#endif // EASYBEHAVIOUR_HPP_
