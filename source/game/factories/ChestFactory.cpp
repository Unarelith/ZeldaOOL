/*
 * =====================================================================================
 *
 *       Filename:  ChestFactory.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 01:13:25
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/audio/AudioPlayer.hpp>
#include <gk/core/input/GamePad.hpp>
#include <gk/core/ApplicationStateStack.hpp>

#include "ChestFactory.hpp"
#include "ChestOpeningState.hpp"
#include "GameKey.hpp"
#include "Scene.hpp"
#include "World.hpp"

#include "ChestComponent.hpp"
#include "CollisionComponent.hpp"
#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"

void chestAction(SceneObject &chest, SceneObject &object, bool inCollision);

SceneObject ChestFactory::create(u16 tileX, u16 tileY) {
	SceneObject object{"Chest", "Tile"};
	object.set<ChestComponent>();
	object.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);

	auto &collisionComponent = object.set<CollisionComponent>();
	collisionComponent.addAction(&chestAction);

	auto &hitboxComponent = object.set<HitboxComponent>();
	hitboxComponent.addHitbox(0, 0, 16, 16);

	return object;
}

void chestAction(SceneObject &chest, SceneObject &object, bool inCollision) {
	auto &chestPosition = chest.get<PositionComponent>();

	if(inCollision && Scene::isPlayer(object) && !chest.get<ChestComponent>().opened) {
		auto &playerPosition = object.get<PositionComponent>();

		// FIXME: Find a better way to find if the player is facing the chest
		if(playerPosition.direction == Direction::Up
		&& playerPosition.y > chestPosition.y
		&& gk::GamePad::isKeyPressedOnce(GameKey::A)) {
			gk::AudioPlayer::playEffect("chest");

			World::getInstance().currentMap()->setTile(chestPosition.x / 16,
			                                           chestPosition.y / 16, 240, true, true);

			gk::ApplicationStateStack::getInstance().push<ChestOpeningState>(chest, &gk::ApplicationStateStack::getInstance().top());

			chest.get<ChestComponent>().opened = true;
		}
	}
}

