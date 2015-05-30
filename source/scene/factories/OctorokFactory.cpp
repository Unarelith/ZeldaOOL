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
	SceneObject octorok("Octorok", "Monster");
	octorok.set<HealthComponent>(2);
	octorok.set<PositionComponent>(x, y, 16, 16);
	octorok.set<MovementComponent>(new OctorokMovement);
	
	auto &collisionComponent = octorok.set<CollisionComponent>();
	collisionComponent.addChecker(&PlayerFactory::mapCollisions);
	collisionComponent.addChecker([](SceneObject &octorok) {
		Map::currentMap->scene().checkCollisionsFor(octorok);
	});
	
	collisionComponent.addAction(&octorokAction);
	
	auto &hitboxesComponent = octorok.set<HitboxesComponent>();
	hitboxesComponent.addHitbox(IntRect(0, 0, 16, 16));
	
	auto &effectsComponent = octorok.set<EffectsComponent>();
	effectsComponent.addEffect("grass", "animations-grassEffect");
	effectsComponent.addEffect("lowWater", "animations-lowWaterEffect");
	
	auto &spriteComponent = octorok.set<Sprite>("enemies-octorok", 16, 16);
	spriteComponent.addAnimation({4, 0}, 150);
	spriteComponent.addAnimation({5, 1}, 150);
	spriteComponent.addAnimation({6, 2}, 150);
	spriteComponent.addAnimation({7, 3}, 150);
	
	return octorok;
}

#include "BattleSystem.hpp"
#include "WeaponComponent.hpp"

void octorokAction(SceneObject &octorok, SceneObject &object, CollisionInformations &collisionInformations) {
	if(!collisionInformations.empty()) {
		if(Scene::isPlayer(object)) {
			BattleSystem::hurt(octorok, object);
		}
		else if(object.has<WeaponComponent>()) {
			// auto &weaponComponent = object.get<WeaponComponent>();
			// if(weaponComponent.weaponInfos.strength()) {
				BattleSystem::hurt(object, octorok);
			// }
		}
	}
}

