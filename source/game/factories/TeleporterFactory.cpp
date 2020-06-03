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
// #include <gk/audio/AudioPlayer.hpp> // FIXME: GAMEKIT
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/Scene.hpp>

#include "PositionComponent.hpp"
#include "TeleporterComponent.hpp"
#include "TeleporterTransition.hpp"
#include "TeleporterFactory.hpp"
#include "TransitionState.hpp"

gk::SceneObject TeleporterFactory::create(float tileX, float tileY) {
	gk::SceneObject object{"Teleporter", "Tile"};
	object.set<TeleporterComponent>();
	object.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);

	auto &hitboxComponent = object.set<gk::HitboxComponent>();
	hitboxComponent.addHitbox(4, 4, 8, 6);

	auto &collisionComponent = object.set<gk::CollisionComponent>();
	collisionComponent.addAction(&TeleporterFactory::teleporterAction);

	return object;
}

void TeleporterFactory::teleporterAction(gk::SceneObject &teleporter, gk::SceneObject &object, bool inCollision) {
	auto &teleporterComponent = teleporter.get<TeleporterComponent>();

	static bool playerOnDoor = false;

	if(object.type() == "Player") {
		if(inCollision) {
			if(!playerOnDoor) {
				// gk::AudioPlayer::playSound("sfx-mapStairs"); // FIXME: GAMEKIT

				auto &state = gk::ApplicationStateStack::getInstance().push<TransitionState>(&gk::ApplicationStateStack::getInstance().top());
				state.setTransition<TeleporterTransition>(teleporterComponent.area(),
				                                          teleporterComponent.mapX(),
				                                          teleporterComponent.mapY(),
				                                          teleporterComponent.playerX(),
				                                          teleporterComponent.playerY(),
				                                          teleporterComponent.playerDirection());

				playerOnDoor = true;
			}
		} else {
			playerOnDoor = false;
		}
	}
}

