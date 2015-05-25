/*
 * =====================================================================================
 *
 *       Filename:  SwordFactory.cpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 17:29:56
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Map.hpp"
#include "SwordBehaviour.hpp"
#include "SwordFactory.hpp"

#include "BehaviourComponent.hpp"
#include "CollisionComponent.hpp"
#include "HitboxesComponent.hpp"
#include "LifetimeComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "WeaponComponent.hpp"

SceneObject SwordFactory::create(float x, float y, GameKey key, SceneObject &owner, Weapon &weaponInfos) {
	SceneObject object;
	object.set<BehaviourComponent>(new SwordBehaviour);
	object.set<LifetimeComponent>();
	object.set<WeaponComponent>(owner, weaponInfos, key, "Sword");
	//object.set<std::string>("Sword");
	
	auto &positionComponent = object.set<PositionComponent>(x, y, 16, 16);
	positionComponent.direction = owner.get<PositionComponent>().direction;
	
	auto &hitboxesComponent = object.set<HitboxesComponent>();
	hitboxesComponent.addHitbox(IntRect( 0,  7, 15,  6), "swordLeftLHand",      false);
	hitboxesComponent.addHitbox(IntRect(10,  0,  6, 15), "swordUpRhand",        false);
	hitboxesComponent.addHitbox(IntRect( 1,  0,  6, 15), "swordUpLHand",        false);
	hitboxesComponent.addHitbox(IntRect( 1,  1, 15,  6), "swordRightLHand",     false);
	hitboxesComponent.addHitbox(IntRect( 1,  0, 15, 15), "swordSwingRightDown", false);
	hitboxesComponent.addHitbox(IntRect( 0,  0, 15, 15), "swordSwingLeftUp",    false);
	hitboxesComponent.addHitbox(IntRect( 1,  0, 15, 15), "swordSwingRightUp",   false);
	hitboxesComponent.addHitbox(IntRect( 1,  0, 15, 15), "swordSwingLeftDown",  false);
	hitboxesComponent.addHitbox(IntRect( 9,  0,  6, 15), "swordDownLHand",      false);
	hitboxesComponent.addHitbox(IntRect( 0,  8, 15,  6), "swordRightRHand",     false);
	hitboxesComponent.addHitbox(IntRect( 1,  8, 15,  6), "swordLeftRHand",      false);
	hitboxesComponent.addHitbox(IntRect( 1,  1,  6, 15), "swordDownRHand",      false);
	
	auto &collisionComponent = object.set<CollisionComponent>();
	collisionComponent.addChecker([](SceneObject &sword) {
		Map::currentMap->scene().checkCollisionsFor(sword);
	});
	
	auto &spriteComponent = object.set<SpriteComponent>("animations-sword", 16, 16);
	
	std::vector<std::vector<Vector2i>> swordPosition = {
		{{-15,   0}, {-13,  15}, {-13,  15}, { -1,  16}, { -1,  16}, { -1,  16}, { -1,  14}},
		{{ -5, -15}, { 12, -12}, { 12, -12}, { 15,   1}, { 15,   1}, { 15,   1}, { 12,   1}},
		{{  5, -15}, {-12, -12}, {-12, -12}, {-15,   1}, {-15,   1}, {-15,   1}, {-12,   1}},
		{{ 14,   4}, { 12, -12}, { 12, -12}, {  0, -15}, {  0, -15}, {  0, -15}, {  0, -11}}
	};
	
	std::vector<Vector2i> spinAttackPosition = {
		{ -1,  16}, {-12,  12}, {-15,  1}, {-12, -12},
		{  0, -15}, { 11, -12}, { 15,  2}, { 13,  13}
	};
	
	// Swinging
	spriteComponent.sprite.addAnimation({0, 4, 4,  8,  8,  8,  8}, swordPosition[0], 40);
	spriteComponent.sprite.addAnimation({1, 5, 5,  9,  9,  9,  9}, swordPosition[1], 40);
	spriteComponent.sprite.addAnimation({2, 6, 6, 10, 10, 10, 10}, swordPosition[2], 40);
	spriteComponent.sprite.addAnimation({3, 5, 5, 11, 11, 11, 11}, swordPosition[3], 40);
	
	// Loading
	spriteComponent.sprite.addAnimation({12,  8}, {swordPosition[0][6], swordPosition[0][6]}, 60);
	spriteComponent.sprite.addAnimation({13,  9}, {swordPosition[1][6], swordPosition[1][6]}, 60);
	spriteComponent.sprite.addAnimation({14, 10}, {swordPosition[2][6], swordPosition[2][6]}, 60);
	spriteComponent.sprite.addAnimation({15, 11}, {swordPosition[3][6], swordPosition[3][6]}, 60);
	
	// SpinAttack
	spriteComponent.sprite.addAnimation({8, 4, 10, 6, 11, 5, 9, 7}, spinAttackPosition, 50);
	
	return object;
}

