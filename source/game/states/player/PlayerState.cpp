/*
 * =====================================================================================
 *
 *       Filename:  PlayerState.cpp
 *
 *    Description:
 *
 *        Created:  22/09/2018 18:13:15
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "GamePad.hpp"
#include "GamePadMovement.hpp"
#include "PlayerState.hpp"
#include "PlayerGrabState.hpp"
#include "PlayerSwordState.hpp"
#include "SceneObjectList.hpp"
#include "TilesInfos.hpp"
#include "WeaponFactory.hpp"
#include "World.hpp"

#include "HealthComponent.hpp"
#include "SpriteComponent.hpp"
#include "StateComponent.hpp"
#include "WeaponComponent.hpp"

void PlayerState::update(SceneObject &player) {
	weaponAction(player);
	updateSprite(player);
}

void PlayerState::updateSprite(SceneObject &player) {
	auto &sprite = player.get<SpriteComponent>();
	sprite.setState(m_state, player);
}

void PlayerState::weaponAction(SceneObject &player) {
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
			SceneObject *weaponObject = &objects.addObject(WeaponFactory::create(*weapon, position.x, position.y, key, player));

			auto &stateComponent = player.get<StateComponent>();
			std::string state = weaponObject->get<WeaponComponent>().playerState;
			if (state == "Sword") {
				stateComponent.setState(player, std::make_shared<PlayerSwordState>(weaponObject));
			}
			else if (state == "Grab" && m_state == "Push") {
				stateComponent.setState(player, std::make_shared<PlayerGrabState>(weaponObject));
			}
		}
	}
}

