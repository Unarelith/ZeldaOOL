/*
 * =====================================================================================
 *
 *       Filename:  PlayerFactory.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 22:02:26
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"
#include "PlayerFactory.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

SceneObject PlayerFactory::create(float x, float y) {
	SceneObject object;
	object.setComponent<PositionComponent>(x, y, 16, 16);
	object.setComponent<MovementComponent>(new GamePadMovement);
	
	SpriteComponent *spriteComponent = object.setComponent<SpriteComponent>("characters-link", 16, 16);
	spriteComponent->sprite.addAnimation({4, 0}, 110);
	spriteComponent->sprite.addAnimation({5, 1}, 110);
	spriteComponent->sprite.addAnimation({6, 2}, 110);
	spriteComponent->sprite.addAnimation({7, 3}, 110);
	spriteComponent->isAnimated = true;
	
	return object;
}

