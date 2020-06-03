/*
 * =====================================================================================
 *
 *       Filename:  OctorokFactory.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 02:23:58
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>
#include <gk/scene/component/MovementComponent.hpp>

#include "EasyBehaviour.hpp"
#include "Map.hpp"
#include "OctorokFactory.hpp"
#include "OctorokMovement.hpp"
#include "PlayerMapCollision.hpp"
#include "Sprite.hpp"
#include "World.hpp"

#include "BehaviourComponent.hpp"
#include "EffectsComponent.hpp"
#include "HealthComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "LootComponent.hpp"

gk::SceneObject OctorokFactory::create(float x, float y) {
	gk::SceneObject octorok("Octorok", "Monster");
	octorok.set<HealthComponent>(2);
	octorok.set<gk::MovementComponent>(new OctorokMovement);
	octorok.set<PositionComponent>(x, y, 16, 16, Direction::Down);

	auto &collisionComponent = octorok.set<gk::CollisionComponent>();
	collisionComponent.addChecker(&PlayerMapCollision::update);
	collisionComponent.addChecker([](gk::SceneObject &octorok) {
		World::getInstance().currentMap()->scene().checkCollisionsFor(octorok);
	});

	collisionComponent.addAction(&OctorokFactory::octorokAction);

	auto &hitboxComponent = octorok.set<gk::HitboxComponent>();
	hitboxComponent.addHitbox(0, 0, 16, 16);

	auto &effectsComponent = octorok.set<EffectsComponent>();
	effectsComponent.addEffect("grass", "animations-grassEffect", 16, 16);
	effectsComponent.addEffect("lowWater", "animations-lowWaterEffect", 16, 16);

	// FIXME: Fix effect system
	auto &destroyEffect = effectsComponent.addEffect("destroy", "animations-monsterDestroy", 32, 32, {-8, -8});
	destroyEffect.addAnimation({{0, 1, 0, 1, 0, 2, 3, 3, 2, 2, 3, 3, 2, 4, 4, 5, 5, 4, 6, 7}, 10, false});

	octorok.set<BehaviourComponent>(new EasyBehaviour([](gk::SceneObject &) {},
	[x, y](gk::SceneObject &octorok) {
		octorok = create(x, y);
	}));

	auto &spriteComponent = octorok.set<Sprite>("enemies-octorok", 16, 16);
	spriteComponent.addAnimation({{4, 0}, 150});
	spriteComponent.addAnimation({{5, 1}, 150});
	spriteComponent.addAnimation({{6, 2}, 150});
	spriteComponent.addAnimation({{7, 3}, 150});

	auto &lootComponent = octorok.set<LootComponent>();
	lootComponent.addItem(1, CollectableType::Rupees);

	return octorok;
}

// #include <gk/audio/AudioPlayer.hpp> // FIXME: GAMEKIT
#include "BattleController.hpp"
#include "WeaponComponent.hpp"

void OctorokFactory::octorokAction(gk::SceneObject &octorok, gk::SceneObject &object, bool inCollision) {
	if(inCollision) {
		if(object.type() == "Player") {
			// gk::AudioPlayer::playSound("sfx-linkHurt"); // FIXME: GAMEKIT
			BattleController::hurt(octorok, object);
		}
		else if(object.has<WeaponComponent>()) {
			// auto &weaponComponent = object.get<WeaponComponent>();
			// if(weaponComponent.weaponInfos.strength()) {
				// gk::AudioPlayer::playSound("sfx-enemyHit"); // FIXME: GAMEKIT
				BattleController::hurt(object, octorok);

				auto &positionComponent = octorok.get<PositionComponent>();

				// FIXME: Items drop too soon
				if(octorok.get<HealthComponent>().life() == 0)
					octorok.get<LootComponent>().dropItem(positionComponent.x, positionComponent.y);
			// }
		}
	}
}

