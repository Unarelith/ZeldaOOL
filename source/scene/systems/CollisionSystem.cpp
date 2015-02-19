/*
 * =====================================================================================
 *
 *       Filename:  CollisionSystem.cpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 02:24:01
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "CollisionSystem.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

bool CollisionSystem::inCollision(SceneObject &object1, SceneObject &object2) {
	auto *position1 = object1.getComponent<PositionComponent>();
	auto *position2 = object2.getComponent<PositionComponent>();
	
	auto *movement1 = object1.getComponent<MovementComponent>();
	auto *movement2 = object2.getComponent<MovementComponent>();
	
	if(position1 && position2) {
		FloatRect rect1(position1->x + position1->hitbox.x,
						position1->y + position1->hitbox.y,
						position1->hitbox.width, position1->hitbox.height);
		FloatRect rect2(position2->x + position2->hitbox.x,
						position2->y + position2->hitbox.y,
						position2->hitbox.width, position2->hitbox.height);
		
		if(movement1) {
			rect1.x += movement1->vx;
			rect1.y += movement1->vy;
		}
		
		if(movement2) {
			rect2.x += movement2->vx;
			rect2.y += movement2->vy;
		}
		
		return rect1.intersects(rect2);
	} else {
		return false;
	}
}

