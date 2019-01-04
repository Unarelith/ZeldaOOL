/*
 * =====================================================================================
 *
 *       Filename:  PlayerSwordState.cpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 19:08:02
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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

