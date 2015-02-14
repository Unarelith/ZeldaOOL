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

SceneObject PlayerFactory::create() {
	SceneObject object;
	object.setComponent<PositionComponent>(0, 0, 16, 16);
	object.setComponent<MovementComponent>(new GamePadMovement);
	
	SpriteComponent *spriteComponent = object.setComponent<SpriteComponent>("characters-link", 16, 16);
	spriteComponent->sprite.addAnimation({4, 0}, 150);
	spriteComponent->sprite.addAnimation({5, 1}, 150);
	spriteComponent->sprite.addAnimation({6, 2}, 150);
	spriteComponent->sprite.addAnimation({7, 3}, 150);
	spriteComponent->isAnimated = true;
	
	return object;
}

