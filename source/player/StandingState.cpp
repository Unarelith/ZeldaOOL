/*
 * =====================================================================================
 *
 *       Filename:  StandingState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  29/08/2014 04:51:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "EffectManager.hpp"
#include "StandingState.hpp"
#include "MovingState.hpp"

StandingState::StandingState() {
	m_stateType = StateType::TypeStanding;
	m_nextStateType = StateType::TypeStanding;
}

StandingState::~StandingState() {
}

void StandingState::update() {
	if(Keyboard::isKeyPressed(Keyboard::A)) {
		m_nextStateType = StateType::TypeSword;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Left)
	|| Keyboard::isKeyPressed(Keyboard::Right)
	|| Keyboard::isKeyPressed(Keyboard::Up)
	|| Keyboard::isKeyPressed(Keyboard::Down)) {
		m_nextStateType = StateType::TypeMoving;
	}
}

void StandingState::draw() {
	m_player.drawFrame(m_player.x(), m_player.y(), m_player.direction());
	
	EffectManager::drawEffects(&m_player);
}

