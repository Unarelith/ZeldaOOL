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
		
		if(movement.movement) movement.movement->process(object);
		
		movement.isBlocked = false;
	}
	
	if(object.has<CollisionComponent>()) {
		object.get<CollisionComponent>().checkCollisions(object);
	}
	
	if(object.has<PositionComponent>() && object.has<MovementComponent>()) {
		auto &position = object.get<PositionComponent>();
		auto &movement = object.get<MovementComponent>();
		
		movement.isMoving = (movement.vx || movement.vy) ? true : false;
		
		position.move(movement.vx * movement.speed,
		              movement.vy * movement.speed);
		
		movement.vx = 0;
		movement.vy = 0;
	}
}

