/*
 * =====================================================================================
 *
 *       Filename:  OctorokFactory.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 02:23:58
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "EasyBehaviour.hpp"
#include "Map.hpp"
#include "OctorokFactory.hpp"
#include "OctorokMovement.hpp"
#include "PlayerFactory.hpp"
#include "Sprite.hpp"

#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "EffectsComponent.hpp"
#include "HealthComponent.hpp"
#include "HitboxComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "LootComponent.hpp"

void octorokAction(SceneObject &octorok, SceneObject &object, bool inCollision);

SceneObject OctorokFactory::create(float x, float y) {
	SceneObject octorok("Monster", "Octorok");
	octorok.set<HealthComponent>(2);
	octorok.set<MovementComponent>(new OctorokMovement);
	octorok.set<PositionComponent>(x, y, 16, 16, Direction::Down);

	auto &collisionComponent = octorok.set<CollisionComponent>();
	collisionComponent.addChecker(&PlayerFactory::mapCollisions);
	collisionComponent.addChecker([](SceneObject &octorok) {
		Map::currentMap->scene().checkCollisionsFor(octorok);
	});

	collisionComponent.addAction(&octorokAction);

	auto &hitboxComponent = octorok.set<HitboxComponent>();
	hitboxComponent.addHitbox(0, 0, 16, 16);

	auto &effectsComponent = octorok.set<EffectsComponent>();
	effectsComponent.addEffect("grass", "animations-grassEffect", 16, 16);
	effectsComponent.addEffect("lowWater", "animations-lowWaterEffect", 16, 16);

	auto &destroyEffect = effectsComponent.addEffect("destroy", "animations-monsterDestroy", 32, 32, {-8, -8});
	destroyEffect.addAnimation({{0, 1, 0, 1, 0, 2, 3, 3, 2, 2, 3, 3, 2, 4, 4, 5, 5, 4, 6, 7}, 10, false});

	octorok.set<BehaviourComponent>(new EasyBehaviour([](SceneObject &) {},
	[x, y](SceneObject &octorok) {
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

#include "BattleSystem.hpp"
#include "WeaponComponent.hpp"

void octorokAction(SceneObject &octorok, SceneObject &object, bool inCollision) {
	if(inCollision) {
		if(Scene::isPlayer(object)) {
			BattleSystem::hurt(octorok, object);
		}
		else if(object.has<WeaponComponent>()) {
			// auto &weaponComponent = object.get<WeaponComponent>();
			// if(weaponComponent.weaponInfos.strength()) {
				BattleSystem::hurt(object, octorok);

				auto &positionComponent = octorok.get<PositionComponent>();

				// FIXME: Items drop too soon
				if(octorok.get<HealthComponent>().life() == 0)
					octorok.get<LootComponent>().dropItem(positionComponent.x, positionComponent.y);
			// }
		}
	}
}

