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
#include <gk/scene/component/MovementComponent.hpp>

#include "StateComponent.hpp"
#include "PlayerMovingState.hpp"

#include "PlayerPushState.hpp"
#include "PlayerStandingState.hpp"

void PlayerMovingState::onBegin(gk::SceneObject &) {
	m_state = "Moving";
}

void PlayerMovingState::onEnd(gk::SceneObject &) {
}

void PlayerMovingState::update(gk::SceneObject &object) {
	auto &movement = object.get<gk::MovementComponent>();
	auto &state = object.get<StateComponent>();
	if(!movement.isMoving)
		state.setState<PlayerStandingState>(object);
	else if(movement.isBlocked.x || movement.isBlocked.y)
		state.setState<PlayerPushState>(object);
	else
		PlayerState::update(object);
}

