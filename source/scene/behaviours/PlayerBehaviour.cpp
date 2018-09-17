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
#include "TilesInfos.hpp"
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

		if (m_state == "Grab") {
			movement.isDirectionLocked = true;
			movement.speed = 0;
		}
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
	}
	else if(m_state == "Grab") {
		if (movement.isMoving)
			m_state = "Lift";

		if (movement.speed != 0 || !GamePad::isKeyPressed(m_weapon->get<WeaponComponent>().key)) {
			movement.isDirectionLocked = false;
			movement.speed = 0.4f;
			m_state = "Standing";
		}
	}
	else if(m_state == "Lift") {
		if (!movement.isMoving)
			m_state = "Grab";

		if (movement.speed != 0 || !GamePad::isKeyPressed(m_weapon->get<WeaponComponent>().key)) {
			movement.isDirectionLocked = false;
			movement.speed = 0.4f;
			m_state = "Standing";
		}

		auto &positionComponent = player.get<PositionComponent>();
		if (Map::currentMap->isTile(positionComponent.getFrontTile().x * 16,
		                            positionComponent.getFrontTile().y * 16,
		                            TilesInfos::Stone) && movement.isMoving)
		{
			movement.isDirectionLocked = false;
			movement.speed = 0.4f;
			m_state = "Standing";

			Map::currentMap->setTile(positionComponent.getFrontTile().x,
			                         positionComponent.getFrontTile().y, 36);
		}
	}
	else {
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
	auto &sprite = player.get<SpriteComponent>();

	if (m_state == "Sword") {
	 	std::string swordState = m_weapon->get<BehaviourComponent>().behaviour->state();
		if (swordState == "Loading" || swordState == "Loaded")
			sprite.setAnimated(movement.isMoving);
		else
			sprite.setAnimated(true);

		sprite.setState(m_state + swordState, player);
	}
	else {
		sprite.setState(m_state, player);
	}
}

