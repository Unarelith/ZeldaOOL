/*
 * =====================================================================================
 *
 *       Filename:  ButtonFactory.cpp
 *
 *    Description:  
 *
 *        Created:  19/02/2015 01:50:40
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ButtonComponent.hpp"
#include "ButtonFactory.hpp"
#include "CollisionComponent.hpp"
#include "Scene.hpp"
#include "PositionComponent.hpp"

void buttonAction(SceneObject &button, SceneObject &object, bool collision);

SceneObject ButtonFactory::create(u16 tileX, u16 tileY) {
	SceneObject object;
	
	auto *positionComponent = object.setComponent<PositionComponent>(tileX * 16, tileY * 16, 16, 16);
	positionComponent->hitbox.reset(4, 4, 8, 8);
	
	auto *buttonComponent = object.setComponent<ButtonComponent>();
	buttonComponent->addTileChange(7, 6, 36);
	buttonComponent->addTileChange(8, 6, 36);
	
	auto *collisionComponent = object.setComponent<CollisionComponent>();
	collisionComponent->addAction(&buttonAction);
	
	return object;
}

void buttonAction(SceneObject &button, SceneObject &object, bool collision) {
	auto *positionComponent = button.getComponent<PositionComponent>();
	auto *buttonComponent = button.getComponent<ButtonComponent>();
	
	if(Scene::isPlayer(object)) {
		if(collision) {
			buttonComponent->pressedAction(positionComponent->x / 16,
			                               positionComponent->y / 16);
		} else {
			buttonComponent->releasedAction(positionComponent->x / 16,
			                                positionComponent->y / 16);
		}
	}
}

