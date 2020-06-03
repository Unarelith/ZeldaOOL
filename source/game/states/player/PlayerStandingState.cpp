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
#include <gk/scene/component/MovementComponent.hpp>

#include "StateComponent.hpp"
#include "PlayerStandingState.hpp"

#include "PlayerPushState.hpp"
#include "PlayerMovingState.hpp"

void PlayerStandingState::onBegin(gk::SceneObject &) {
	m_state = "Standing";
}

void PlayerStandingState::onEnd(gk::SceneObject &) {
}

void PlayerStandingState::update(gk::SceneObject &object) {
	auto &movement = object.get<gk::MovementComponent>();
	auto &state = object.get<StateComponent>();
	if(movement.isMoving)
		state.setState<PlayerMovingState>(object);
	else if(movement.isBlocked.x || movement.isBlocked.y)
		state.setState<PlayerPushState>(object);
	else
		PlayerState::update(object);
}

