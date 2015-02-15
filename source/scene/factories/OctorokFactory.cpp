/*
 * =====================================================================================
 *
 *       Filename:  OctorokFactory.cpp
 *
 *    Description:  
 *
 *        Created:  15/02/2015 01:06:34
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "MovementComponent.hpp"
#include "OctorokFactory.hpp"
#include "OctorokMovement.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

SceneObject OctorokFactory::create(float x, float y) {
	SceneObject object;
	object.setComponent<PositionComponent>(x, y, 16, 16);
	object.setComponent<MovementComponent>(new OctorokMovement);
	
	SpriteComponent *spriteComponent = object.setComponent<SpriteComponent>("enemies-octorok", 16, 16);
	spriteComponent->sprite.addAnimation({4, 0}, 150);
	spriteComponent->sprite.addAnimation({5, 1}, 150);
	spriteComponent->sprite.addAnimation({6, 2}, 150);
	spriteComponent->sprite.addAnimation({7, 3}, 150);
	spriteComponent->isAnimated = true;
	
	return object;
}

