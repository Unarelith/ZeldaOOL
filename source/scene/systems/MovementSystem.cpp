/*
 * =====================================================================================
 *
 *       Filename:  MovementSystem.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:59:42
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "CollisionComponent.hpp"
#include "MovementComponent.hpp"
#include "MovementSystem.hpp"
#include "PositionComponent.hpp"

void MovementSystem::process(SceneObject &object) {
	if(object.has<PositionComponent>() && object.has<MovementComponent>()) {
		auto &positionComponent = object.get<PositionComponent>();
		auto &movementComponent = object.get<MovementComponent>();
		
		movementComponent.movement->process(object);
		
		movementComponent.isBlocked = false;
		
		if(object.has<CollisionComponent>()) {
			object.get<CollisionComponent>().checkCollisions(object);
		}
		
		movementComponent.isMoving = (movementComponent.vx || movementComponent.vy) ? true : false;
		
		positionComponent.move(movementComponent.vx * movementComponent.speed,
		                       movementComponent.vy * movementComponent.speed);
		
		movementComponent.vx = 0;
		movementComponent.vy = 0;
	}
}

