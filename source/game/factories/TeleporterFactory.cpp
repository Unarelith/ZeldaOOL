/*
 * =====================================================================================
 *
 *       Filename:  TeleporterFactory.cpp
 *
 *    Description:
 *
 *        Created:  19/02/2015 17:51:46
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/core/ApplicationStateStack.hpp>

#include "AudioPlayer.hpp"
#include "TeleporterTransition.hpp"
#include "Scene.hpp"
#include "TeleporterFactory.hpp"
#include "TransitionState.hpp"

#include "CollisionComponent.hpp"
#include "HitboxComponent.hpp"
#include "PositionComponent.hpp"
#include "TeleporterComponent.hpp"

void teleporterAction(SceneObject &teleporter, SceneObject &object, bool inCollision);

SceneObject TeleporterFactory::create(float tileX, float tileY) {
	SceneObject object{"Teleporter", "Tile"};
	object.set<TeleporterComponent>();
	object.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);

	auto &hitboxComponent = object.set<HitboxComponent>();
	hitboxComponent.addHitbox(4, 4, 8, 6);

	auto &collisionComponent = object.set<CollisionComponent>();
	collisionComponent.addAction(&teleporterAction);

	return object;
}

void teleporterAction(SceneObject &teleporter, SceneObject &object, bool inCollision) {
	auto &teleporterComponent = teleporter.get<TeleporterComponent>();

	static bool playerOnDoor = false;

	if(Scene::isPlayer(object)) {
		if(inCollision) {
			if(!playerOnDoor) {
				AudioPlayer::playEffect("mapStairs");

				auto &state = gk::ApplicationStateStack::getInstance().push<TransitionState>(&gk::ApplicationStateStack::getInstance().top());
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

