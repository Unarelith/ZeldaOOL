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
#include "SwordBehaviour.hpp"
#include "SwordFactory.hpp"

#include "BehaviourComponent.hpp"
#include "LifetimeComponent.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"
#include "WeaponComponent.hpp"

SceneObject SwordFactory::create(float x, float y, Direction direction, SceneObject &owner) {
	SceneObject object;
	object.set<BehaviourComponent>(new SwordBehaviour);
	object.set<LifetimeComponent>();
	object.set<WeaponComponent>(owner);
	
	auto &positionComponent = object.set<PositionComponent>(x, y, 16, 16);
	positionComponent.hitbox.reset(4, 4, 8, 8); // TODO
	positionComponent.direction = direction;
	
	auto &spriteComponent = object.set<SpriteComponent>("animations-sword", 16, 16);
	
	std::vector<std::vector<std::pair<s16, s16>>> swordPosition = {
		{{-15,   0}, {-13,  15}, {-13,  15}, { -1,  16}, { -1,  16}, { -1,  16}, { -1,  14}},
		{{ -5, -15}, { 12, -12}, { 12, -12}, { 15,   1}, { 15,   1}, { 15,   1}, { 12,   1}},
		{{  5, -15}, {-12, -12}, {-12, -12}, {-15,   1}, {-15,   1}, {-15,   1}, {-12,   1}},
		{{ 14,   4}, { 12, -12}, { 12, -12}, {  0, -15}, {  0, -15}, {  0, -15}, {  0, -11}}
	};
	
	std::vector<std::pair<s16, s16>> spinAttackPosition = {
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

