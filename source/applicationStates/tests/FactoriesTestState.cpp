/*
 * =====================================================================================
 *
 *       Filename:  FactoriesTestState.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 21:57:42
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "FactoriesTestState.hpp"
#include "GamePad.hpp"
#include "PlayerFactory.hpp"

FactoriesTestState::FactoriesTestState() {
	m_player = PlayerFactory::create();
}

void FactoriesTestState::update() {
	m_movementSystem.process(m_player);
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void FactoriesTestState::draw() {
	m_font.drawString(24, 2, "Move the player", Color::blue);
	
	m_drawingSystem.draw(m_player);
}

