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
#include "Sprite.hpp"

#include "LifetimeComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "StateComponent.hpp"

void DrawingSystem::draw(SceneObject &object) {
	auto *lifetimeComponent = object.getComponent<LifetimeComponent>();
	auto *positionComponent = object.getComponent<PositionComponent>();
	
	if(positionComponent) {
		if(!lifetimeComponent || !lifetimeComponent->almostDead()
		|| (!lifetimeComponent->dead(object) && lifetimeComponent->aliveTime() % 120 > 59)) {
			if(object.hasComponent<Image>()) {
				drawImage(object, positionComponent->x, positionComponent->y);
			}
			
			if(object.hasComponent<Sprite>()) {
				drawSprite(object, positionComponent->x, positionComponent->y);
			}
		}
	}
}

void DrawingSystem::drawImage(SceneObject &object, float x, float y) {
	object.getComponent<Image>()->draw(x, y);
}

void DrawingSystem::drawSprite(SceneObject &object, float x, float y) {
	auto *movementComponent = object.getComponent<MovementComponent>();
	auto *positionComponent = object.getComponent<PositionComponent>();
	auto *stateComponent = object.getComponent<StateComponent>();
	
	bool animated = false;
	u16 animID = 0;
	
	if(stateComponent) {
		animID = stateComponent->currentAnimation();
		animated = stateComponent->isAnimated();
	}
	else if(movementComponent) {
		animated = movementComponent->isMoving;
	}
	
	if(positionComponent->direction != Direction::None) {
		if(stateComponent) {
			animID += static_cast<s8>(positionComponent->direction);
		} else {
			animID = static_cast<s8>(positionComponent->direction);
		}
	}
	
	if(animated) {
		object.getComponent<Sprite>()->playAnimation(x, y, animID);
	} else {
		object.getComponent<Sprite>()->drawFrame(x, y, animID);
	}
}

