/*
 * =====================================================================================
 *
 *       Filename:  SceneObjectTestState.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 17:38:26
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "GamePad.hpp"
#include "GamePadMovement.hpp"
#include "MovementComponent.hpp"
#include "PositionComponent.hpp"
#include "SceneObjectTestState.hpp"
#include "Sprite.hpp"

SceneObjectTestState::SceneObjectTestState() {
	m_object.set<PositionComponent>(75, 50, 16, 16);
	m_object.set<MovementComponent>(new GamePadMovement);
	
	auto &spriteComponent = m_object.set<Sprite>("characters-link", 16, 16);
	spriteComponent.addAnimation({4, 0}, 110);
	spriteComponent.addAnimation({5, 1}, 110);
	spriteComponent.addAnimation({6, 2}, 110);
	spriteComponent.addAnimation({7, 3}, 110);
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

