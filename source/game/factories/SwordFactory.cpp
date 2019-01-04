/*
 * =====================================================================================
 *
 *       Filename:  SwordFactory.cpp
 *
 *    Description:
 *
 *        Created:  02/05/2015 17:29:56
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include <gk/scene/component/CollisionComponent.hpp>
#include <gk/scene/component/HitboxComponent.hpp>

#include "SwordBehaviour.hpp"
#include "SwordFactory.hpp"
#include "World.hpp"

#include "BehaviourComponent.hpp"
#include "LifetimeComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "WeaponComponent.hpp"

gk::SceneObject SwordFactory::create(float x, float y, gk::GameKey key, gk::SceneObject &owner, Weapon &weaponInfos) {
	gk::SceneObject object("Sword", "Weapon");
	object.set<BehaviourComponent>(new SwordBehaviour);
	object.set<LifetimeComponent>();
	object.set<WeaponComponent>(owner, weaponInfos, key, "Sword");

	auto &positionComponent = object.set<PositionComponent>(x, y, 16, 16);
	positionComponent.direction = owner.get<PositionComponent>().direction;

	auto &hitboxComponent = object.set<gk::HitboxComponent>();
	hitboxComponent.addHitbox( 0,  7, 15,  6); // swordLeftLHand
	hitboxComponent.addHitbox(10,  0,  6, 15); // swordUpRhand
	hitboxComponent.addHitbox( 1,  0,  6, 15); // swordUpLHand
	hitboxComponent.addHitbox( 1,  1, 15,  6); // swordRightLHand
	hitboxComponent.addHitbox( 1,  0, 15, 15); // swordSwingRightDown
	hitboxComponent.addHitbox( 0,  0, 15, 15); // swordSwingLeftUp
	hitboxComponent.addHitbox( 1,  0, 15, 15); // swordSwingRightUp
	hitboxComponent.addHitbox( 1,  0, 15, 15); // swordSwingLeftDown
	// hitboxComponent.addHitbox( 9,  0,  6, 15); // swordDownLHand
	// hitboxComponent.addHitbox( 0,  8, 15,  6); // swordRightRHand
	// hitboxComponent.addHitbox( 1,  8, 15,  6); // swordLeftRHand
	// hitboxComponent.addHitbox( 1,  0,  6, 15); // swordUpLHand
	hitboxComponent.addHitbox(10,  1,  4, 13); // swordDownLHand
	hitboxComponent.addHitbox( 1,  9, 13,  4); // swordRightRHand
	hitboxComponent.addHitbox( 2,  9, 13,  4); // swordLeftRHand
	hitboxComponent.addHitbox( 2,  1,  4, 13); // swordUpLHand

	auto &collisionComponent = object.set<gk::CollisionComponent>();
	collisionComponent.addChecker([](gk::SceneObject &sword) {
		World::getInstance().currentMap()->scene().checkCollisionsFor(sword);
	});

	auto &spriteComponent = object.set<SpriteComponent>("animations-sword", 16, 16);
	spriteComponent.addState("Swinging",    true,  true,  0, 0);
	spriteComponent.addState("Loading",     true,  false, 4, 1);
	spriteComponent.addState("Loaded",      true,  true,  4, 1);
	spriteComponent.addState("SpinAttack",  false, true,  8, 0);

	std::vector<std::vector<gk::Vector2i>> swordPosition = {
		{{-15,   0}, {-13,  15}, {-13,  15}, { -1,  19}, { -1,  19}, { -1,  19}, { -1,  14}},
		{{ -5, -15}, {  8, -12}, {  8, -12}, { 19,   1}, { 19,   1}, { 19,   1}, { 12,   1}},
		{{  5, -15}, { -8, -12}, { -8, -12}, {-19,   1}, {-19,   1}, {-19,   1}, {-12,   1}},
		{{ 14,   4}, { 12, -12}, { 12, -12}, {  0, -18}, {  0, -18}, {  0, -18}, {  0, -11}}
	};

	std::vector<gk::Vector2i> spinAttackPosition = {
		{ -1,  16}, {-12,  12}, {-15,  1}, {-12, -12},
		{  0, -15}, { 11, -12}, { 15,  2}, { 13,  13}
	};

	// Swinging
	spriteComponent.sprite().addAnimation({{0, 4, 4,  8,  8,  8}, swordPosition[0], 45});
	spriteComponent.sprite().addAnimation({{1, 5, 5,  9,  9,  9}, swordPosition[1], 45});
	spriteComponent.sprite().addAnimation({{2, 6, 6, 10, 10, 10}, swordPosition[2], 45});
	spriteComponent.sprite().addAnimation({{3, 5, 5, 11, 11, 11}, swordPosition[3], 45});

	// Loading
	spriteComponent.sprite().addAnimation({{12,  8}, {swordPosition[0][6], swordPosition[0][6]}, 60});
	spriteComponent.sprite().addAnimation({{13,  9}, {swordPosition[1][6], swordPosition[1][6]}, 60});
	spriteComponent.sprite().addAnimation({{14, 10}, {swordPosition[2][6], swordPosition[2][6]}, 60});
	spriteComponent.sprite().addAnimation({{15, 11}, {swordPosition[3][6], swordPosition[3][6]}, 60});

	// SpinAttack
	spriteComponent.sprite().addAnimation({{8, 4, 10, 6, 11, 5, 9, 7}, spinAttackPosition, 50});

	return object;
}

