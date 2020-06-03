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
// #include <gk/audio/AudioPlayer.hpp> // FIXME: GameKit
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/Scene.hpp>

#include "ChestFactory.hpp"
#include "ChestOpeningState.hpp"
#include "GameKey.hpp"
#include "World.hpp"

#include "ChestComponent.hpp"
#include "PositionComponent.hpp"

gk::SceneObject ChestFactory::create(u16 tileX, u16 tileY) {
	gk::SceneObject object{"Chest", "Tile"};
	object.set<ChestComponent>();
	object.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);

	auto &collisionComponent = object.set<gk::CollisionComponent>();
	collisionComponent.addAction(&ChestFactory::chestAction);

	auto &hitboxComponent = object.set<gk::HitboxComponent>();
	hitboxComponent.addHitbox(0, 0, 16, 16);

	return object;
}

void ChestFactory::chestAction(gk::SceneObject &chest, gk::SceneObject &object, bool inCollision) {
	auto &chestPosition = chest.get<PositionComponent>();

	if(inCollision && object.type() == "Player" && !chest.get<ChestComponent>().opened) {
		auto &playerPosition = object.get<PositionComponent>();

		// FIXME: Find a better way to find if the player is facing the chest
		if(playerPosition.direction == Direction::Up
		&& playerPosition.y > chestPosition.y
		&& gk::GamePad::isKeyPressedOnce(GameKey::A)) {
			// gk::AudioPlayer::playSound("sfx-chest"); // FIXME: GAMEKIT

			World::getInstance().currentMap()->setTile(chestPosition.x / 16,
			                                           chestPosition.y / 16, 240, true, true);

			gk::ApplicationStateStack::getInstance().push<ChestOpeningState>(chest, &gk::ApplicationStateStack::getInstance().top());

			chest.get<ChestComponent>().opened = true;
		}
	}
}

