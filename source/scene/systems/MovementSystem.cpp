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
	auto *positionComponent = object.getComponent<PositionComponent>();
	auto *movementComponent = object.getComponent<MovementComponent>();
	auto *collisionComponent = object.getComponent<CollisionComponent>();
	
	if(positionComponent && movementComponent) {
		movementComponent->movement->process(object);
		
		movementComponent->isBlocked = false;
		
		if(collisionComponent) collisionComponent->checkCollisions(object);
		
		movementComponent->isMoving = (movementComponent->vx || movementComponent->vy) ? true : false;
		
		positionComponent->x += movementComponent->vx * movementComponent->speed;
		positionComponent->y += movementComponent->vy * movementComponent->speed;
		
		movementComponent->vx = 0;
		movementComponent->vy = 0;
	}
}

