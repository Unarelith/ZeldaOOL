/*
 * =====================================================================================
 *
 *       Filename:  ChestFactory.cpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 01:13:25
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

#include "ChestComponent.hpp"
#include "CollisionComponent.hpp"
#include "PositionComponent.hpp"

void chestAction(SceneObject &chest, SceneObject &object, bool collision);

SceneObject ChestFactory::create(u16 tileX, u16 tileY) {
	SceneObject object;
	object.set<ChestComponent>();
	object.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);
	
	auto &collisionComponent = object.set<CollisionComponent>();
	collisionComponent.addAction(&chestAction);
	
	return object;
}

void chestAction(SceneObject &chest, SceneObject &object, bool collision) {
	auto &chestPosition = chest.get<PositionComponent>();
	
	if(Scene::isPlayer(object) && collision) {
		auto &playerPosition = object.get<PositionComponent>();
		
		if(playerPosition.direction == Direction::Up
		&& GamePad::isKeyPressedOnce(GameKey::A)
		&& !chest.get<ChestComponent>().opened) {
			AudioPlayer::playEffect("chest");
			
			Map::currentMap->setTile(chestPosition.x / 16,
			                         chestPosition.y / 16, 240, true);
			
			ApplicationStateStack::getInstance().push<ChestOpeningState>(chest, ApplicationStateStack::getInstance().top());
			
			chest.get<ChestComponent>().opened = true;
		}
	}
}
