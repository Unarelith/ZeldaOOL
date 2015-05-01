/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.cpp
 *
 *    Description:  
 *
 *        Created:  01/05/2015 23:58:50
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "DrawingSystem.hpp"
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
			object.get<Image>().draw(position.x, position.y);
		}
	}
}

