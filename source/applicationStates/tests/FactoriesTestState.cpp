/*
 * =====================================================================================
 *
 *       Filename:  FactoriesTestState.cpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 21:57:42
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "ApplicationStateStack.hpp"
#include "CollisionComponent.hpp"
#include "FactoriesTestState.hpp"
#include "GamePad.hpp"
#include "GamePadMovement.hpp"
#include "OctorokFactory.hpp"
#include "PlayerFactory.hpp"

FactoriesTestState::FactoriesTestState() {
	m_player = PlayerFactory::create(75, 50);
	m_player.removeComponent<CollisionComponent>();
	
	m_octoroks.emplace_back(OctorokFactory::create(100, 80));
}

void FactoriesTestState::update() {
	m_movementSystem.process(m_player);
	
	for(auto &it : m_octoroks) {
		m_movementSystem.process(it);
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::A)) {
		m_octoroks.emplace_back(OctorokFactory::create(100, 80));
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::Select)) {
		ApplicationStateStack::getInstance().pop();
	}
}

void FactoriesTestState::draw() {
	m_font.drawString(20, 2, "Move the player", Color::blue);
	m_font.drawString(4, 24, "A: Spawn an Octorok");
	
	m_drawingSystem.draw(m_player);
	
	for(auto &it : m_octoroks) {
		m_drawingSystem.draw(it);
	}
}

