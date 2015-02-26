/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:36:21
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "DrawingSystem.hpp"

#include "Image.hpp"
#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void DrawingSystem::draw(SceneObject &object) {
	auto *position = object.getComponent<PositionComponent>();
	auto *lifetimeComponent = object.getComponent<LifetimeComponent>();
	
	if(position) {
		auto *image = object.getComponent<Image>();
		auto *spriteComponent = object.getComponent<SpriteComponent>();
		
		if(!lifetimeComponent || !lifetimeComponent->almostDead()
		|| (!lifetimeComponent->dead() && lifetimeComponent->aliveTime() % 120 > 59)) {
			if(image) {
				image->draw(position->x, position->y);
			}
			else if(spriteComponent) {
				if(position->direction != Direction::None) {
					spriteComponent->animID = static_cast<s8>(position->direction);
				}
				
				auto *movementComponent = object.getComponent<MovementComponent>();
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
}

