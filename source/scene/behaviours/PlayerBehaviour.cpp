/*
 * =====================================================================================
 *
 *       Filename:  PlayerBehaviour.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 12:42:03
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "GamePad.hpp"
#include "GamePadMovement.hpp"
#include "Map.hpp"
#include "PlayerBehaviour.hpp"
#include "SceneObjectList.hpp"
#include "WeaponFactory.hpp"

#include "BehaviourComponent.hpp"
#include "HealthComponent.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "WeaponComponent.hpp"

void PlayerBehaviour::reset(SceneObject &player) {
	m_state = "Standing";

	if(m_weapon) {
		m_weapon->get<LifetimeComponent>().kill();
		m_weapon = nullptr;
	}

	auto &movementComponent = player.get<MovementComponent>();
	movementComponent.isDirectionLocked = false;
	movementComponent.v = 0;
}

void PlayerBehaviour::action(SceneObject &player) {
	auto &movement = player.get<MovementComponent>();
	auto &health = player.get<HealthComponent>();

	if(health.isHurt) m_state = "Standing";

	if(m_state == "Standing") {
		if(movement.isMoving) m_state = "Moving";
		if(movement.isBlocked) m_state = "Pushing";

		weaponAction(player);
	}
	else if(m_state == "Moving") {
		if(!movement.isMoving) m_state = "Standing";
		if(movement.isBlocked) m_state = "Pushing";

		weaponAction(player);
	}
	else if(m_state == "Pushing") {
		if(!movement.isBlocked) m_state = "Standing";

		weaponAction(player);
	}
	else if(m_state == "Sword") {
		static std::string oldSwordState;

		std::string swordState = m_weapon->get<BehaviourComponent>().behaviour->state();
		if(swordState != oldSwordState) {
			if(swordState == "Swinging") {
				if(!movement.movements.push(nullptr)) {
					m_state = "Standing";
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

				m_state = "Standing";
			}
		}

		oldSwordState = swordState;
	} else {
	 	throw EXCEPTION("Unknown player state:", m_state);
	}

	updateSprite(player);
}

void PlayerBehaviour::weaponAction(SceneObject &player) {
	auto &health = player.get<HealthComponent>();

	if(!health.isHurt) {
		auto &position = player.get<PositionComponent>();
		auto &objects = player.get<SceneObjectList>();

		Weapon *weapon = nullptr;
		GameKey key;
		if(GamePad::isKeyPressedOnce(GameKey::A)) {
			weapon = player.get<InventoryComponent>().getWeaponA();
			key = GameKey::A;
		}
		else if(GamePad::isKeyPressedOnce(GameKey::B)) {
			weapon = player.get<InventoryComponent>().getWeaponB();
			key = GameKey::B;
		}

		if(weapon) {
			m_weapon = &objects.addObject(WeaponFactory::create(*weapon, position.x, position.y, key, player));
			m_state = m_weapon->get<WeaponComponent>().playerState;
		}
	}
}

void PlayerBehaviour::updateSprite(SceneObject &player) {
	auto &movement = player.get<MovementComponent>();
	auto &position = player.get<PositionComponent>();
	auto &sprite = player.get<SpriteComponent>();

	if(m_state == "Standing") {
		sprite.isAnimated = false;
		sprite.animID = static_cast<s8>(position.direction);
		sprite.frameID = 1;
	}
	else if(m_state == "Moving") {
		sprite.isAnimated = true;
		sprite.animID = static_cast<s8>(position.direction);
	}
	else if(m_state == "Pushing") {
		sprite.isAnimated = true;
		sprite.animID = static_cast<s8>(position.direction) + 4;
	}
	else if(m_state == "Sword") {
		std::string swordState = m_weapon->get<BehaviourComponent>().behaviour->state();

		if(swordState == "Swinging") {
			sprite.isAnimated = true;
			sprite.animID = static_cast<s8>(position.direction) + 8;
		}
		else if(swordState == "Loading" && movement.isMoving) {
			sprite.isAnimated = true;
			sprite.animID = static_cast<s8>(position.direction);
		}
		else if(swordState == "SpinAttack") {
			sprite.isAnimated = true;
			sprite.animID = 12;
		} else {
			sprite.isAnimated = false;
			sprite.animID = static_cast<s8>(position.direction);
			sprite.frameID = 1;
		}
	}
}

