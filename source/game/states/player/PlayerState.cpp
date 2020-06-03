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
#include <gk/core/input/GamePad.hpp>
#include <gk/scene/SceneObjectList.hpp>

#include "GameKey.hpp"
#include "GamePadMovement.hpp"
#include "PlayerState.hpp"
#include "PlayerGrabState.hpp"
#include "PlayerSwordState.hpp"
#include "TilesInfos.hpp"
#include "WeaponFactory.hpp"
#include "World.hpp"

#include "HealthComponent.hpp"
#include "SpriteComponent.hpp"
#include "StateComponent.hpp"
#include "WeaponComponent.hpp"

void PlayerState::update(gk::SceneObject &player) {
	weaponAction(player);
	updateSprite(player);
}

void PlayerState::updateSprite(gk::SceneObject &player) {
	auto &sprite = player.get<SpriteComponent>();
	sprite.setState(m_state, player);
}

void PlayerState::weaponAction(gk::SceneObject &player) {
	auto &health = player.get<HealthComponent>();

	if(!health.isHurt) {
		auto &position = player.get<PositionComponent>();
		auto &objects = player.get<gk::SceneObjectList>();

		Weapon *weapon = nullptr;
		gk::GameKey key;
		if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
			weapon = player.get<InventoryComponent>().getWeaponA();
			key = GameKey::A;
		}
		else if(gk::GamePad::isKeyPressedOnce(GameKey::B)) {
			weapon = player.get<InventoryComponent>().getWeaponB();
			key = GameKey::B;
		}

		if(weapon) {
			gk::SceneObject *weaponObject = &objects.addObject(WeaponFactory::create(*weapon, position.x, position.y, key, player));

			auto &stateComponent = player.get<StateComponent>();
			std::string state = weaponObject->get<WeaponComponent>().playerState;
			if (state == "Sword") {
				stateComponent.setState<PlayerSwordState>(player, weaponObject);
			}
			else if (state == "Grab" && m_state == "Push") {
				stateComponent.setState<PlayerGrabState>(player, weaponObject);
			}
		}
	}
}

