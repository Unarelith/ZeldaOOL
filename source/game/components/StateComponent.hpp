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
#ifndef STATECOMPONENT_HPP_
#define STATECOMPONENT_HPP_

#include <memory>

#include "IState.hpp"

class StateComponent {
	using StatePtr = std::shared_ptr<IState>;

	public:
		void update(gk::SceneObject &object);

		template<typename T, typename... Args>
		auto setState(gk::SceneObject &object, Args &&...args) -> typename std::enable_if<std::is_base_of<IState, T>::value, void>::type {
			setState(object, std::make_shared<T>(std::forward<Args>(args)...));
		}

	private:
		void setState(gk::SceneObject &object, StatePtr state);

		StatePtr m_state;
};

#endif // STATECOMPONENT_HPP_
