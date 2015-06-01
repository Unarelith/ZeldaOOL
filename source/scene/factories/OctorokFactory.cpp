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
#include "HitboxesComponent.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void octorokAction(SceneObject &octorok, SceneObject &object, CollisionInformations& collisionInformations);

SceneObject OctorokFactory::create(float x, float y) {
	SceneObject octorok("Octorok", "Monster");
	octorok.set<HealthComponent>(2);
	octorok.set<MovementComponent>(new OctorokMovement);
	octorok.set<PositionComponent>(x, y, 16, 16, Direction::Down);
	
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
	
	auto &destroyEffect = effectsComponent.addEffect("destroy", "animations-monsterDestroy", 32, 32, {-8, -8});
	destroyEffect.addAnimation({0, 1, 0, 1, 0, 2, 3, 3, 2, 2, 3, 3, 2, 4, 4, 5, 5, 4, 6, 7}, 10, false);
	
	octorok.set<BehaviourComponent>(new EasyBehaviour([](SceneObject &octorok) {
		// auto &spriteComponent = octorok.get<SpriteComponent>();
		
		// spriteComponent.animID = static_cast<s8>(octorok.get<PositionComponent>().direction);
	},
	[x, y](SceneObject &octorok) {
		octorok = create(x, y);
	}));
	
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

