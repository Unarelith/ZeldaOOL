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
		
		positionComponent.x += movementComponent.vx * movementComponent.speed;
		positionComponent.y += movementComponent.vy * movementComponent.speed;
		
		movementComponent.vx = 0;
		movementComponent.vy = 0;
	}
}

