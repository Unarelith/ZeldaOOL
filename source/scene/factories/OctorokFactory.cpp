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
#include "Map.hpp"
#include "OctorokFactory.hpp"
#include "OctorokMovement.hpp"
#include "PlayerFactory.hpp"
#include "Sprite.hpp"

#include "CollisionComponent.hpp"
#include "EffectsComponent.hpp"
#include "HealthComponent.hpp"
#include "HitboxesComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

void octorokAction(SceneObject &octorok, SceneObject &object, CollisionInformations& collisionInformations);

SceneObject OctorokFactory::create(float x, float y) {
	SceneObject object;
	object.set<PositionComponent>(x, y, 16, 16);
	object.set<MovementComponent>(new OctorokMovement);
	object.set<HealthComponent>(2);
	
	auto &collisionComponent = object.set<CollisionComponent>();
	collisionComponent.addChecker(&PlayerFactory::mapCollisions);
	collisionComponent.addChecker([](SceneObject &object) {
		Map::currentMap->scene().checkCollisionsFor(object);
	});
	
	collisionComponent.addAction(&octorokAction);
	
	auto &hitboxesComponent = object.set<HitboxesComponent>();
	hitboxesComponent.addHitbox(IntRect(0, 0, 16, 16));
	
	auto &effectsComponent = object.set<EffectsComponent>();
	effectsComponent.addEffect("grass", "animations-grassEffect");
	effectsComponent.addEffect("lowWater", "animations-lowWaterEffect");
	
	auto &spriteComponent = object.set<Sprite>("enemies-octorok", 16, 16);
	spriteComponent.addAnimation({4, 0}, 150);
	spriteComponent.addAnimation({5, 1}, 150);
	spriteComponent.addAnimation({6, 2}, 150);
	spriteComponent.addAnimation({7, 3}, 150);
	
	return object;
}

#include "BattleSystem.hpp"
#include "WeaponComponent.hpp"

void octorokAction(SceneObject &octorok, SceneObject &object, CollisionInformations &collisionInformations) {
	if(Scene::isPlayer(object) && !collisionInformations.empty()) {
		BattleSystem::hurt(octorok, object);
	}
	else if(object.has<WeaponComponent>()) {
		// auto &weaponComponent = object.get<WeaponComponent>();
		// if(weaponComponent.weaponInfos.strength()) {
			BattleSystem::hurt(object, octorok);
		// }
	}
}

