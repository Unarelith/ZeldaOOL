/*
 * =====================================================================================
 *
 *       Filename:  CollisionHelper.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 00:09:30
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
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

			rect1 += position1.position();
			rect2 += position2.position();

			if(object1.has<gk::MovementComponent>()) {
				rect1 += object1.get<gk::MovementComponent>().v;
			}

			if(object2.has<gk::MovementComponent>()) {
				rect2 += object2.get<gk::MovementComponent>().v;
			}

			if(object1.has<SpriteComponent>()) {
				rect1 += object1.get<SpriteComponent>().sprite().currentAnimation().currentPosition();
			}

			if(object2.has<SpriteComponent>()) {
				rect2 += object2.get<SpriteComponent>().sprite().currentAnimation().currentPosition();
			}

			if(rect1.intersects(rect2)) {
				return true;
			}
		}
	}

	return false;
}

