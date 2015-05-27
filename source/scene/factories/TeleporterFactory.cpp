/*
 * =====================================================================================
 *
 *       Filename:  TeleporterFactory.cpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 17:51:46
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "AudioPlayer.hpp"
#include "TeleporterTransition.hpp"
#include "Scene.hpp"
#include "TeleporterFactory.hpp"
#include "TransitionState.hpp"

#include "CollisionComponent.hpp"
#include "HitboxesComponent.hpp"
#include "PositionComponent.hpp"
#include "TeleporterComponent.hpp"

void teleporterAction(SceneObject &teleporter, SceneObject &object, CollisionInformations &collisionInformations);

SceneObject TeleporterFactory::create(float tileX, float tileY) {
	SceneObject object;
	object.set<TeleporterComponent>();
	object.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);
	
	auto &hitboxesComponent = object.set<HitboxesComponent>();
	hitboxesComponent.addHitbox(IntRect(4, 4, 8, 6));
	
	auto &collisionComponent = object.set<CollisionComponent>();
	collisionComponent.addAction(&teleporterAction);
	
	return object;
}

void teleporterAction(SceneObject &teleporter, SceneObject &object, CollisionInformations &collisionInformations) {
	auto &teleporterComponent = teleporter.get<TeleporterComponent>();
	
	static bool playerOnDoor = false;
	
	if(Scene::isPlayer(object)) {
		if(!collisionInformations.empty()) {
			if(!playerOnDoor) {
				AudioPlayer::playEffect("mapStairs");
				
				auto &state = ApplicationStateStack::getInstance().push<TransitionState>(ApplicationStateStack::getInstance().top());
				state.setTransition<TeleporterTransition>(teleporterComponent.area(),
				                                          teleporterComponent.mapX(),
				                                          teleporterComponent.mapY(),
				                                          teleporterComponent.playerX(),
				                                          teleporterComponent.playerY(),
				                                          teleporterComponent.playerDirection());
				
				playerOnDoor = true;
			}
		} else {
			playerOnDoor = false;
		}
	}
}

