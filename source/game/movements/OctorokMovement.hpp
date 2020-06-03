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
#ifndef OCTOROKMOVEMENT_HPP_
#define OCTOROKMOVEMENT_HPP_

#include <gk/core/Timer.hpp>
#include <gk/core/Vector2.hpp>

#include <gk/scene/movement/Movement.hpp>

class OctorokMovement : public gk::Movement {
	public:
		enum class State {
			Standing,
			Moving
		};

		void reset(gk::SceneObject &object);

		void process(gk::SceneObject &object) override;

	private:
		State m_state = State::Standing;

		gk::Timer m_timer;

		gk::Vector2f m_v = {0.0f, 0.0f};

		float m_movementCounter = 0;

		u16 m_randomMinTimeToWait = 1000;
		u16 m_randomMaxMovement = 48;
};

#endif // OCTOROKMOVEMENT_HPP_
