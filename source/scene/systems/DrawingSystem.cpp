/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:36:21
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "DrawingSystem.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void DrawingSystem::draw(SceneObject &object) {
	auto position = object.getComponent<PositionComponent>();
	
	if(position) {
		auto spriteComponent = object.getComponent<SpriteComponent>();
		
		if(spriteComponent) {
			if(position->direction != Direction::None) {
				spriteComponent->animID = static_cast<s8>(position->direction);
			}
			
			auto movementComponent = object.getComponent<MovementComponent>();
			if(movementComponent) {
				spriteComponent->isAnimated = movementComponent->isMoving;
			}
			
			if(spriteComponent->isAnimated) {
				spriteComponent->sprite.playAnimation(position->x, position->y, spriteComponent->animID);
			} else {
				spriteComponent->sprite.drawFrame(position->x, position->y, spriteComponent->animID);
			}
		}
	}
}

