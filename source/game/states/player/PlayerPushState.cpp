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
#include "MovementComponent.hpp"
#include "StateComponent.hpp"
#include "PlayerPushState.hpp"
#include "PlayerStandingState.hpp"

void PlayerPushState::onBegin(SceneObject &) {
	m_state = "Push";
}

void PlayerPushState::onEnd(SceneObject &) {
}

void PlayerPushState::update(SceneObject &object) {
	auto &movement = object.get<MovementComponent>();
	auto &state = object.get<StateComponent>();
	if(!movement.isBlocked)
		state.setState<PlayerStandingState>(object);
	else
		PlayerState::update(object);
}

