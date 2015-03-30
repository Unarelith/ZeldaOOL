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
#include "StateComponent.hpp"

void DrawingSystem::draw(SceneObject &object) {
	auto *lifetimeComponent = object.getComponent<LifetimeComponent>();
	auto *positionComponent = object.getComponent<PositionComponent>();
	
	if(positionComponent) {
		auto *image = object.getComponent<Image>();
		auto *spriteComponent = object.getComponent<SpriteComponent>();
		
		if(!lifetimeComponent || !lifetimeComponent->almostDead()
		|| (!lifetimeComponent->dead(object) && lifetimeComponent->aliveTime() % 120 > 59)) {
			if(image) {
				image->draw(positionComponent->x, positionComponent->y);
			}
			else if(spriteComponent) {
				auto *movementComponent = object.getComponent<MovementComponent>();
				auto *stateComponent = object.getComponent<StateComponent>();
				
				if(stateComponent) {
					spriteComponent->animID = stateComponent->currentAnimation();
					spriteComponent->isAnimated = stateComponent->isAnimated();
				}
				else if(movementComponent) {
					spriteComponent->isAnimated = movementComponent->isMoving;
				}
				
				if(positionComponent->direction != Direction::None) {
					if(stateComponent) {
						spriteComponent->animID += static_cast<s8>(positionComponent->direction);
					} else {
						spriteComponent->animID = static_cast<s8>(positionComponent->direction);
					}
				}
				
				if(spriteComponent->isAnimated) {
					spriteComponent->sprite.playAnimation(positionComponent->x,
					                                      positionComponent->y,
					                                      spriteComponent->animID);
				} else {
					spriteComponent->sprite.drawFrame(positionComponent->x,
					                                  positionComponent->y,
					                                  spriteComponent->animID);
				}
			}
		}
	}
}

