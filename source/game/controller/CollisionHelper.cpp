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
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/component/MovementComponent.hpp>

#include "CollisionHelper.hpp"
#include "Sprite.hpp"

#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

bool CollisionHelper::inCollision(gk::SceneObject &object1, gk::SceneObject &object2) {
	if(object1.has<PositionComponent>() && object1.has<gk::HitboxComponent>()
	&& object2.has<PositionComponent>() && object2.has<gk::HitboxComponent>()) {
		auto &hitbox1 = object1.get<gk::HitboxComponent>();
		auto &hitbox2 = object2.get<gk::HitboxComponent>();

		if(hitbox1.currentHitbox() && hitbox2.currentHitbox()) {
			auto &position1 = object1.get<PositionComponent>();
			auto &position2 = object2.get<PositionComponent>();

			gk::FloatRect rect1 = *hitbox1.currentHitbox();
			gk::FloatRect rect2 = *hitbox2.currentHitbox();

			rect1.x += position1.x;
			rect1.y += position1.y;

			rect2.x += position2.x;
			rect2.y += position2.y;

			if(object1.has<gk::MovementComponent>()) {
				auto &movement = object1.get<gk::MovementComponent>();
				rect1.x += movement.v.x;
				rect1.y += movement.v.y;
			}

			if(object2.has<gk::MovementComponent>()) {
				auto &movement = object2.get<gk::MovementComponent>();
				rect2.x += movement.v.x;
				rect2.y += movement.v.y;
			}

			if(object1.has<SpriteComponent>()) {
				auto &pos = object1.get<SpriteComponent>().sprite().currentAnimation().currentPosition();
				rect1.x += pos.x;
				rect1.y += pos.y;
			}

			if(object2.has<SpriteComponent>()) {
				auto &pos = object2.get<SpriteComponent>().sprite().currentAnimation().currentPosition();
				rect2.x += pos.x;
				rect2.y += pos.y;
			}

			if(rect1.intersects(rect2)) {
				return true;
			}
		}
	}

	return false;
}

