/*
 * =====================================================================================
 *
 *       Filename:  MovementSystem.cpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:27:38
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "MovementSystem.hpp"

#include "CollisionComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

void MovementSystem::process(SceneObject &object) {
	if(object.has<MovementComponent>()) {
		auto &movement = object.get<MovementComponent>();
		
		if(!movement.movements.empty() && movement.movements.top()) {
			movement.movements.top()->process(object);
		}
		
		movement.isBlocked = false;
	}
	
	if(object.has<CollisionComponent>()) {
		object.get<CollisionComponent>().checkCollisions(object);
	}
	
	if(object.has<PositionComponent>() && object.has<MovementComponent>()) {
		auto &position = object.get<PositionComponent>();
		auto &movement = object.get<MovementComponent>();
		
		movement.isMoving = (movement.v.x || movement.v.y) ? true : false;
		
		position.move(movement.v * movement.speed);
		
		movement.v = 0;
	}
}

