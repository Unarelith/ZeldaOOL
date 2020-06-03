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
#include <gk/resource/ResourceHandler.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/MovementComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/SceneObjectList.hpp>

#include "GameKey.hpp"
#include "GamePadMovement.hpp"
#include "PlayerFactory.hpp"
#include "World.hpp"
#include "EffectsComponent.hpp"
#include "HealthComponent.hpp"
#include "InventoryComponent.hpp"
#include "PlayerMapCollision.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

#include "PlayerStandingState.hpp"
#include "StateComponent.hpp"

gk::SceneObject PlayerFactory::create(float x, float y) {
	gk::SceneObject player{"Link", "Player"};
	player.set<SpriteComponent>("sprite-characters-link");
	player.set<HealthComponent>(13 * 4, 11 * 4);
	player.set<gk::MovementComponent>(new GamePadMovement).speed = 0.4f;
	player.set<gk::SceneObjectList>();

	auto &stateComponent = player.set<StateComponent>();
	stateComponent.setState<PlayerStandingState>(player);

	auto &positionComponent = player.set<PositionComponent>(x, y, 16, 16);
	positionComponent.direction = Direction::Down;

	auto &hitboxComponent = player.set<gk::HitboxComponent>();
	hitboxComponent.addHitbox(4, 5, 8, 10);

	auto &collisionComponent = player.set<gk::CollisionComponent>();
	collisionComponent.addChecker(&PlayerMapCollision::update);
	collisionComponent.addChecker([](gk::SceneObject &player) {
		World::getInstance().currentMap()->scene().checkCollisionsFor(player);
	});

	auto &effectsComponent = player.set<EffectsComponent>();
	effectsComponent.addEffect("grass", "animations-grassEffect", 16, 16);
	effectsComponent.addEffect("lowWater", "animations-lowWaterEffect", 16, 16, {0, 8}).addAnimation({{0, 1, 2}, 150});

	auto &inventoryComponent = player.set<InventoryComponent>();
	inventoryComponent.addWeapon("swordL1");
	inventoryComponent.addWeapon("strengthL1");
	inventoryComponent.equipWeapon(0, 0, GameKey::A);
	inventoryComponent.equipWeapon(0, 1, GameKey::B);

	return player;
}

