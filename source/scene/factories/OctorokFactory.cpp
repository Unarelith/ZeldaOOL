/*
 * =====================================================================================
 *
 *       Filename:  OctorokFactory.cpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 01:06:34
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "OctorokFactory.hpp"
#include "OctorokMovement.hpp"
#include "Sprite.hpp"

#include "MovementComponent.hpp"
#include "PositionComponent.hpp"

SceneObject OctorokFactory::create(float x, float y) {
	SceneObject object;
	object.set<PositionComponent>(x, y, 16, 16);
	object.set<MovementComponent>(new OctorokMovement);
	
	auto &spriteComponent = object.set<Sprite>("enemies-octorok", 16, 16);
	spriteComponent.addAnimation({4, 0}, 150);
	spriteComponent.addAnimation({5, 1}, 150);
	spriteComponent.addAnimation({6, 2}, 150);
	spriteComponent.addAnimation({7, 3}, 150);
	
	return object;
}

