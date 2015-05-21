/*
 * =====================================================================================
 *
 *       Filename:  CollisionSystem.cpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 00:09:30
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "CollisionSystem.hpp"
#include "Sprite.hpp"

#include "CollisionComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void CollisionSystem::checkCollision(SceneObject &object1, SceneObject &object2) {
	CollisionInformations collisionInformations;
	
	inCollision(object1, object2, collisionInformations);
	
	if(object1.has<CollisionComponent>()) {
		object1.get<CollisionComponent>().collisionActions(object1, object2, collisionInformations);
	}
	
	if(object2.has<CollisionComponent>()) {
		object2.get<CollisionComponent>().collisionActions(object2, object1, collisionInformations);
	}
}

void CollisionSystem::inCollision(SceneObject &object1, SceneObject &object2, CollisionInformations &collisionInformations) {
	if(object1.has<PositionComponent>() && object1.has<HitboxesComponent>()
	&& object2.has<PositionComponent>() && object2.has<HitboxesComponent>()) {
		auto &position1 = object1.get<PositionComponent>();
		auto &hitboxes1 = object1.get<HitboxesComponent>();
		
		auto &position2 = object2.get<PositionComponent>();
		auto &hitboxes2 = object2.get<HitboxesComponent>();
		
		float offset1x = position1.x;
		float offset1y = position1.y;
		float offset2x = position2.x;
		float offset2y = position2.y;
		
		if(object1.has<MovementComponent>()) {
			offset1x += object1.get<MovementComponent>().vx;
			offset1y += object1.get<MovementComponent>().vy;
		}
		
		if(object2.has<MovementComponent>()) {
			offset2x += object2.get<MovementComponent>().vx;
			offset2y += object2.get<MovementComponent>().vy;
		}
		
		if(object1.has<SpriteComponent>()) {
			offset1x += object1.get<SpriteComponent>().sprite.currentAnimation().currentPosition().first;
			offset1y += object1.get<SpriteComponent>().sprite.currentAnimation().currentPosition().second;
		}
		
		if(object2.has<SpriteComponent>()) {
			offset2x += object2.get<SpriteComponent>().sprite.currentAnimation().currentPosition().first;
			offset2y += object2.get<SpriteComponent>().sprite.currentAnimation().currentPosition().second;
		}
		
		for(size_t i = 0; i < hitboxes1.size(); i++)
			for(size_t j = 0; j < hitboxes2.size(); j++){
				if(hitboxes1[i].isEnabled && hitboxes2[j].isEnabled) {
					FloatRect rect1(hitboxes1[i].rect.x + offset1x,
					                hitboxes1[i].rect.y + offset1y,
					                hitboxes1[i].rect.width,
					                hitboxes1[i].rect.height);
					FloatRect rect2(hitboxes2[j].rect.x + offset2x,
					                hitboxes2[j].rect.y + offset2y,
					                hitboxes2[j].rect.width,
					                hitboxes2[j].rect.height);
					
					if(rect1.intersects(rect2)) {
						collisionInformations.addInformation(hitboxes1[i], hitboxes2[j]);
					}
				}
			}
	}
}

