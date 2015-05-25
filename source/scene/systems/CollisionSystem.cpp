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
		
		Vector2f offset1 = position1.position();
		Vector2f offset2 = position2.position();
		
		if(object1.has<MovementComponent>()) {
			offset1 += object1.get<MovementComponent>().v;
		}
		
		if(object2.has<MovementComponent>()) {
			offset2 += object2.get<MovementComponent>().v;
		}
		
		if(object1.has<SpriteComponent>()) {
			u16 animID = object1.get<SpriteComponent>().animID;
			offset1 += object1.get<SpriteComponent>().sprite.getAnimation(animID).currentPosition();
		}
		
		if(object2.has<SpriteComponent>()) {
			u16 animID = object2.get<SpriteComponent>().animID;
			offset2 += object2.get<SpriteComponent>().sprite.getAnimation(animID).currentPosition();
		}
		
		for(size_t i = 0; i < hitboxes1.size(); i++)
			for(size_t j = 0; j < hitboxes2.size(); j++){
				if(hitboxes1[i].isEnabled && hitboxes2[j].isEnabled) {
					FloatRect rect1(hitboxes1[i].rect.position() + offset1, hitboxes1[i].rect.width, hitboxes1[i].rect.height);
					FloatRect rect2(hitboxes2[j].rect.position() + offset2, hitboxes2[j].rect.width, hitboxes2[j].rect.height);
					
					if(rect1.intersects(rect2)) {
						collisionInformations.addInformation(hitboxes1[i], hitboxes2[j]);
					}
				}
			}
	}
}

