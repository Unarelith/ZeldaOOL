/*
 * =====================================================================================
 *
 *       Filename:  DrawingSystem.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 19:36:21
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "DrawingSystem.hpp"
#include "PositionComponent.hpp"
#include "SpriteComponent.hpp"

void DrawingSystem::draw(SceneObject &object) {
	PositionComponent *position = object.getComponent<PositionComponent>();
	
	if(position) {
		SpriteComponent *spriteComponent = object.getComponent<SpriteComponent>();
		
		if(spriteComponent) {
			if(spriteComponent->isAnimated) {
				spriteComponent->sprite.playAnimation(position->x, position->y, spriteComponent->animID);
			} else {
				spriteComponent->sprite.drawFrame(position->x, position->y, spriteComponent->sprite.lastFrameDisplayed());
			}
		}
	}
}

