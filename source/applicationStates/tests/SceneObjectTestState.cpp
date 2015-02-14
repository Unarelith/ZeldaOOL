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
	m_object.setComponent<PositionComponent>(0, 0, 16, 16);
	m_object.setComponent<MovementComponent>(new GamePadMovement);
	
	SpriteComponent *spriteComponent = m_object.setComponent<SpriteComponent>("characters-link", 16, 16);
	spriteComponent->sprite.addAnimation({4, 0}, 150);
	spriteComponent->isAnimated = true;
}

void SceneObjectTestState::update() {
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		SpriteComponent *spriteComponent = m_object.getComponent<SpriteComponent>();
		spriteComponent->isAnimated = !spriteComponent->isAnimated;
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
	
	m_movementSystem.process(m_object);
}

void SceneObjectTestState::draw() {
	m_font.drawString(24, 2, "Move the player", Color::blue);
	m_font.drawString(4, 24, "A: Toggle animation");
	
	m_drawingSystem.draw(m_object);
}

