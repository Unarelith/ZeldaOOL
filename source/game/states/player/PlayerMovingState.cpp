/*
 * =====================================================================================
 *
 *       Filename:  PlayerMovingState.cpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 18:46:22
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "MovementComponent.hpp"
#include "StateComponent.hpp"
#include "PlayerMovingState.hpp"

#include "PlayerPushState.hpp"
#include "PlayerStandingState.hpp"

void PlayerMovingState::onBegin(SceneObject &) {
	m_state = "Moving";
}

void PlayerMovingState::onEnd(SceneObject &) {
}

void PlayerMovingState::update(SceneObject &object) {
	auto &movement = object.get<MovementComponent>();
	auto &state = object.get<StateComponent>();
	if(!movement.isMoving)
		state.setState<PlayerStandingState>(object);
	else if(movement.isBlocked)
		state.setState<PlayerPushState>(object);
	else
		PlayerState::update(object);
}

