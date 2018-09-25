/*
 * =====================================================================================
 *
 *       Filename:  PlayerStandingState.cpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 18:38:50
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "MovementComponent.hpp"
#include "StateComponent.hpp"
#include "PlayerStandingState.hpp"

#include "PlayerPushState.hpp"
#include "PlayerMovingState.hpp"

void PlayerStandingState::onBegin(SceneObject &) {
	m_state = "Standing";
}

void PlayerStandingState::onEnd(SceneObject &) {
}

void PlayerStandingState::update(SceneObject &object) {
	auto &movement = object.get<MovementComponent>();
	auto &state = object.get<StateComponent>();
	if(movement.isMoving)
		state.setState<PlayerMovingState>(object);
	else if(movement.isBlocked)
		state.setState<PlayerPushState>(object);
	else
		PlayerState::update(object);
}

