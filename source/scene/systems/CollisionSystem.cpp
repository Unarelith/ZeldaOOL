/*
 * =====================================================================================
 *
 *       Filename:  CollisionSystem.cpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 02:24:01
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "CollisionSystem.hpp"
#include "Sprite.hpp"

#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

bool CollisionSystem::inCollision(SceneObject &object1, SceneObject &object2) {
	if(object1.has<PositionComponent>() && object2.has<PositionComponent>()) {
		auto &position1 = object1.get<PositionComponent>();
		auto &position2 = object2.get<PositionComponent>();
		
		FloatRect rect1(position1.x + position1.hitbox.x,
						position1.y + position1.hitbox.y,
						position1.hitbox.width, position1.hitbox.height);
		FloatRect rect2(position2.x + position2.hitbox.x,
						position2.y + position2.hitbox.y,
						position2.hitbox.width, position2.hitbox.height);
		
		if(object1.has<MovementComponent>()) {
			rect1.x += object1.get<MovementComponent>().vx;
			rect1.y += object1.get<MovementComponent>().vy;
		}
		
		if(object2.has<MovementComponent>()) {
			rect2.x += object2.get<MovementComponent>().vx;
			rect2.y += object2.get<MovementComponent>().vy;
		}
		
		if(object1.has<Sprite>() && object1.get<Sprite>().hasAnimations()) {
			rect1.x += object1.get<Sprite>().currentAnimation().currentPosition().first;
			rect1.y += object1.get<Sprite>().currentAnimation().currentPosition().second;
		}
		
		if(object2.has<Sprite>() && object2.get<Sprite>().hasAnimations()) {
			rect2.x += object2.get<Sprite>().currentAnimation().currentPosition().first;
			rect2.y += object2.get<Sprite>().currentAnimation().currentPosition().second;
		}
		
		return rect1.intersects(rect2);
	} else {
		return false;
	}
}

