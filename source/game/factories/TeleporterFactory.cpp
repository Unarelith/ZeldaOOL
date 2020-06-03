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
// #include <gk/audio/AudioPlayer.hpp> // FIXME: GAMEKIT
#include <gk/core/ApplicationStateStack.hpp>
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/Scene.hpp>

#include "PositionComponent.hpp"
#include "TeleporterComponent.hpp"
#include "TeleporterTransition.hpp"
#include "TeleporterFactory.hpp"
#include "TransitionState.hpp"

gk::SceneObject TeleporterFactory::create(float tileX, float tileY) {
	gk::SceneObject object{"Teleporter", "Tile"};
	object.set<TeleporterComponent>();
	object.set<PositionComponent>(tileX * 16, tileY * 16, 16, 16);

	auto &hitboxComponent = object.set<gk::HitboxComponent>();
	hitboxComponent.addHitbox(4, 4, 8, 6);

	auto &collisionComponent = object.set<gk::CollisionComponent>();
	collisionComponent.addAction(&TeleporterFactory::teleporterAction);

	return object;
}

void TeleporterFactory::teleporterAction(gk::SceneObject &teleporter, gk::SceneObject &object, bool inCollision) {
	auto &teleporterComponent = teleporter.get<TeleporterComponent>();

	static bool playerOnDoor = false;

	if(object.type() == "Player") {
		if(inCollision) {
			if(!playerOnDoor) {
				// gk::AudioPlayer::playSound("sfx-mapStairs"); // FIXME: GAMEKIT

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

