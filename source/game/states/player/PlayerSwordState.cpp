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

#include "BehaviourComponent.hpp"
#include "GamePadMovement.hpp"
#include "LifetimeComponent.hpp"
#include "PlayerStandingState.hpp"
#include "PlayerSwordState.hpp"
#include "SpriteComponent.hpp"
#include "StateComponent.hpp"

void PlayerSwordState::onBegin(gk::SceneObject &) {
	m_state = "Sword";
}

void PlayerSwordState::onEnd(gk::SceneObject &) {
}

void PlayerSwordState::update(gk::SceneObject &object) {
	static std::string oldSwordState;

	auto &movement = object.get<gk::MovementComponent>();
	auto &state = object.get<StateComponent>();

	std::string swordState = m_weapon->get<BehaviourComponent>().behaviour->state();
	if(swordState != oldSwordState) {
		if(swordState == "Swinging") {
			if(!movement.movements.push(nullptr)) {
				state.setState<PlayerStandingState>(object);
			}
		}
		else if(swordState == "Loading") {
			movement.movements.top().reset(new GamePadMovement);

			movement.isDirectionLocked = true;
		}
		else if(swordState == "SpinAttack") {
			movement.movements.top().reset(nullptr);

			movement.isDirectionLocked = false;
		}
		else if(swordState == "Finished") {
			m_weapon->get<LifetimeComponent>().kill();
			m_weapon = nullptr;

			movement.movements.pop();

			movement.isDirectionLocked = false;

			state.setState<PlayerStandingState>(object);
		}
	}

	oldSwordState = swordState;

	if (m_weapon)
		updateSprite(object);
}

void PlayerSwordState::updateSprite(gk::SceneObject &object) {
	auto &sprite = object.get<SpriteComponent>();
	auto &movement = object.get<gk::MovementComponent>();

	std::string swordState = m_weapon->get<BehaviourComponent>().behaviour->state();
	if (swordState == "Loading" || swordState == "Loaded")
		sprite.setAnimated(movement.isMoving);
	else
		sprite.setAnimated(true);

	sprite.setState(m_state + swordState, object);
}

