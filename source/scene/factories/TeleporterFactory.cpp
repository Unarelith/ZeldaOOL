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
#include "DoorTransition.hpp"
#include "Scene.hpp"
#include "TeleporterFactory.hpp"
#include "TransitionState.hpp"

#include "CollisionComponent.hpp"
#include "PositionComponent.hpp"
#include "TeleporterComponent.hpp"

void teleporterAction(SceneObject &teleporter, SceneObject &object, bool collision);

SceneObject TeleporterFactory::create(u16 tileX, u16 tileY) {
	SceneObject object;
	object.setComponent<TeleporterComponent>();
	
	auto *positionComponent = object.setComponent<PositionComponent>(tileX * 16, tileY * 16, 16, 16);
	positionComponent->hitbox.reset(4, 4, 8, 8);
	
	auto *collisionComponent = object.setComponent<CollisionComponent>();
	collisionComponent->addAction(&teleporterAction);
	
	return object;
}

void teleporterAction(SceneObject &teleporter, SceneObject &object, bool collision) {
	auto *teleporterComponent = teleporter.getComponent<TeleporterComponent>();
	
	if(Scene::isPlayer(object)) {
		if(collision && teleporterComponent->isActivated()) {
			auto &state = ApplicationStateStack::getInstance().push<TransitionState>(ApplicationStateStack::getInstance().top());
			state.setTransition<DoorTransition>(teleporterComponent->area(),
			                                    teleporterComponent->mapX(),
			                                    teleporterComponent->mapY(),
			                                    teleporterComponent->playerX(),
			                                    teleporterComponent->playerY(),
			                                    teleporterComponent->playerDirection());
			
			teleporterComponent->toggleOFF();
		} else {
			teleporterComponent->toggleON();
		}
	}
}

