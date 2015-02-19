/*
 * =====================================================================================
 *
 *       Filename:  TeleporterFactory.cpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 17:51:46
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "CollisionComponent.hpp"
#include "PositionComponent.hpp"
#include "Scene.hpp"
#include "TeleporterFactory.hpp"

void teleporterAction(SceneObject &teleporter, SceneObject &object, bool collision);

SceneObject TeleporterFactory::create(u16 tileX, u16 tileY) {
	SceneObject object;
	
	auto *positionComponent = object.setComponent<PositionComponent>(tileX * 16, tileY * 16, 16, 16);
	positionComponent->hitbox.reset(0, 0, 16, 16);
	
	auto *collisionComponent = object.setComponent<CollisionComponent>();
	collisionComponent->addAction(&teleporterAction);
	
	return object;
}

#include "ApplicationStateStack.hpp"
#include "DoorTransition.hpp"
#include "TransitionState.hpp"

void teleporterAction(SceneObject &teleporter, SceneObject &object, bool collision) {
	if(Scene::isPlayer(object)) {
		if(collision) {
			ApplicationStateStack::getInstance().push<TransitionState>(new DoorTransition(1, 0, 0, 4.5 * 16, 6 * 16, Direction::Up), ApplicationStateStack::getInstance().top());
		} else {
			
		}
	}
}

