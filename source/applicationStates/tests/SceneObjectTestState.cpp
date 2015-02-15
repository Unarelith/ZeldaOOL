/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectTestState.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 17:38:26
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SceneObjectTestState.hpp"
#include "SpriteComponent.hpp"

SceneObjectTestState::SceneObjectTestState() {
	m_object.setComponent<PositionComponent>(75, 50, 16, 16);
	m_object.setComponent<MovementComponent>(new GamePadMovement);
	
	SpriteComponent *spriteComponent = m_object.setComponent<SpriteComponent>("characters-link", 16, 16);
	spriteComponent->sprite.addAnimation({4, 0}, 110);
	spriteComponent->sprite.addAnimation({5, 1}, 110);
	spriteComponent->sprite.addAnimation({6, 2}, 110);
	spriteComponent->sprite.addAnimation({7, 3}, 110);
	spriteComponent->isAnimated = true;
}

void SceneObjectTestState::update() {
	m_movementSystem.process(m_object);
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void SceneObjectTestState::draw() {
	m_font.drawString(20, 2, "Move the player", Color::blue);
	
	m_drawingSystem.draw(m_object);
}

