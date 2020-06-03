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
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/component/MovementComponent.hpp>
#include <gk/scene/Scene.hpp>

#include "GameKey.hpp"
#include "MessageBoxState.hpp"
#include "NPCFactory.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

gk::SceneObject NPCFactory::create(u16 tileX, u16 tileY) {
	gk::SceneObject npc{"NPC", "NPC"};
	npc.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16).direction = Direction::Down;

	auto &hitboxComponent = npc.set<gk::HitboxComponent>();
	//hitboxComponent.addHitbox(0, 6, 16, 10);
	hitboxComponent.addHitbox(0, 0, 16, 16);

	auto &collisionComponent = npc.set<gk::CollisionComponent>();
	collisionComponent.addAction(&NPCFactory::npcAction);

	auto &spriteComponent = npc.set<SpriteComponent>("characters-blueBoy", 16, 16);
	spriteComponent.sprite().addAnimation({{0, 4}, 250});
	spriteComponent.sprite().addAnimation({{1, 5}, 250});
	spriteComponent.sprite().addAnimation({{2, 6}, 250});
	spriteComponent.sprite().addAnimation({{3, 7}, 250});

	spriteComponent.addState("Standing", true, true, 0, 0);
	spriteComponent.setState("Standing", npc);

	return npc;
}

void NPCFactory::npcAction(gk::SceneObject &npc, gk::SceneObject &object, bool inCollision) {
	if(object.type() == "Player" && inCollision) {
		auto &playerPosition = object.get<PositionComponent>();
		auto &playerMovement = object.get<gk::MovementComponent>();

		auto &npcPosition = npc.get<PositionComponent>();

		if(playerPosition.intersectionDirection(npcPosition) == 1) {
			playerMovement.v.x = 0;
		} else {
			playerMovement.v.y = 0;
		}

		// FIXME: Fix priorities with weaponA
		if(gk::GamePad::isKeyPressedOnce(GameKey::A)) {
			gk::ApplicationStateStack::getInstance().push<MessageBoxState>("L'[1]Arbre Bojo[0] est tout à l'est de cette grotte.", &gk::ApplicationStateStack::getInstance().top());
		}
	}
}

