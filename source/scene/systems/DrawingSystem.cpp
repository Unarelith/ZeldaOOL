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

void DrawingSystem::draw(SceneObject &object) {
	if(object.has<PositionComponent>()) {
		auto &position = object.get<PositionComponent>();
		
		if(object.has<LifetimeComponent>()) {
			auto &lifetime = object.get<LifetimeComponent>();
			if(lifetime.almostDead() && (lifetime.dead(object) || lifetime.aliveTime() % 120 <= 59)) return;
		}
		
		if(object.has<Image>()) {
			drawImage(object, position.x, position.y);
		}
		
		if(object.has<Sprite>()) {
			drawSprite(object, position.x, position.y);
		}
	}
}

void DrawingSystem::drawImage(SceneObject &object, float x, float y) {
	object.get<Image>().draw(x, y);
}

void DrawingSystem::drawSprite(SceneObject &object, float x, float y) {
	bool animated = false;
	u16 animID = 0;
	
	if(object.has<MovementComponent>()) {
		animated = object.get<MovementComponent>().isMoving;
	}
	
	if(object.get<PositionComponent>().direction != Direction::None) {
		animID += static_cast<s8>(object.get<PositionComponent>().direction);
	}
	
	if(animated) {
		object.get<Sprite>().playAnimation(x, y, animID);
	} else {
		object.get<Sprite>().drawFrame(x, y, animID);
	}
}

