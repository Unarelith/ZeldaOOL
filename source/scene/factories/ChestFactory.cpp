/*
 * =====================================================================================
 *
 *       Filename:  ChestFactory.cpp
 *
 *    Description:  
 *
 *        Created:  24/02/2015 01:31:14
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "AudioPlayer.hpp"
#include "ChestFactory.hpp"
#include "ChestOpeningState.hpp"
#include "GamePad.hpp"
#include "Map.hpp"
#include "Scene.hpp"

#include "CollisionComponent.hpp"
#include "PositionComponent.hpp"

void chestAction(SceneObject &chest, SceneObject &object, bool collision);

SceneObject ChestFactory::create(u16 tileX, u16 tileY) {
	SceneObject object;
	
	object.setComponent<PositionComponent>(tileX * 16, tileY * 16, 16, 16);
	
	auto *collisionComponent = object.setComponent<CollisionComponent>();
	collisionComponent->addAction(&chestAction);
	
	return object;
}

void chestAction(SceneObject &chest, SceneObject &object, bool collision) {
	auto *chestPosition = chest.getComponent<PositionComponent>();
	
	if(Scene::isPlayer(object) && collision) {
		auto *positionComponent = object.getComponent<PositionComponent>();
		
		if(positionComponent->direction == Direction::Up
		&& GamePad::isKeyPressedOnce(GameKey::A)) {
			AudioPlayer::playEffect("chest");
			
			Map::currentMap->setTile(chestPosition->x / 16,
			                         chestPosition->y / 16, 240);
			
			ApplicationStateStack::getInstance().push<ChestOpeningState>(chest, ApplicationStateStack::getInstance().top());
		}
	}
}

