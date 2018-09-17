/*
 * =====================================================================================
 *
 *       Filename:  CollisionHelper.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 00:09:30
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "CollisionHelper.hpp"
#include "Sprite.hpp"

#include "CollisionComponent.hpp"
#include "HitboxComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void CollisionHelper::checkCollision(SceneObject &object1, SceneObject &object2) {
	bool inCollision = CollisionHelper::inCollision(object1, object2);

	if(object1.has<CollisionComponent>()) {
		object1.get<CollisionComponent>().collisionActions(object1, object2, inCollision);
	}

	if(object2.has<CollisionComponent>()) {
		object2.get<CollisionComponent>().collisionActions(object2, object1, inCollision);
	}
}

bool CollisionHelper::inCollision(SceneObject &object1, SceneObject &object2) {
	if(object1.has<PositionComponent>() && object1.has<HitboxComponent>()
	&& object2.has<PositionComponent>() && object2.has<HitboxComponent>()) {
		auto &hitbox1 = object1.get<HitboxComponent>();
		auto &hitbox2 = object2.get<HitboxComponent>();

		if(hitbox1.currentHitbox() && hitbox2.currentHitbox()) {
			auto &position1 = object1.get<PositionComponent>();
			auto &position2 = object2.get<PositionComponent>();

			FloatRect rect1 = *hitbox1.currentHitbox();
			FloatRect rect2 = *hitbox2.currentHitbox();

			rect1 += position1.position();
			rect2 += position2.position();

			if(object1.has<MovementComponent>()) {
				rect1 += object1.get<MovementComponent>().v;
			}

			if(object2.has<MovementComponent>()) {
				rect2 += object2.get<MovementComponent>().v;
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

