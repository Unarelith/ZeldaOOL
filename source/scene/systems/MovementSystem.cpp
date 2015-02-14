/*
 * =====================================================================================
 *
 *       Filename:  MovementSystem.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:59:42
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "MovementComponent.hpp"
#include "MovementSystem.hpp"
#include "PositionComponent.hpp"

void MovementSystem::process(SceneObject &object) {
	PositionComponent *positionComponent = object.getComponent<PositionComponent>();
	MovementComponent *movementComponent = object.getComponent<MovementComponent>();
	
	if(positionComponent && movementComponent) {
		movementComponent->movement->process(object);
		
		positionComponent->x += movementComponent->vx * movementComponent->speed;
		positionComponent->y += movementComponent->vy * movementComponent->speed;
		
		movementComponent->vx = 0;
		movementComponent->vy = 0;
	}
}

