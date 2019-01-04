/*
 * =====================================================================================
 *
 *       Filename:  PlayerPushState.cpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 18:48:00
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/scene/component/MovementComponent.hpp>

#include "StateComponent.hpp"
#include "PlayerPushState.hpp"
#include "PlayerStandingState.hpp"

void PlayerPushState::onBegin(gk::SceneObject &) {
	m_state = "Push";
}

void PlayerPushState::onEnd(gk::SceneObject &) {
}

void PlayerPushState::update(gk::SceneObject &object) {
	auto &movement = object.get<gk::MovementComponent>();
	auto &state = object.get<StateComponent>();
	if(!movement.isBlocked.x && !movement.isBlocked.y)
		state.setState<PlayerStandingState>(object);
	else
		PlayerState::update(object);
}

