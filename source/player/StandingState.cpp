/*
 * =====================================================================================
 *
 *       Filename:  StandingState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:24:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "StandingState.hpp"
#include "MovingState.hpp"

StandingState::StandingState() {
	m_stateType = StateType::TypeStanding;
	m_nextStateType = StateType::TypeStanding;
}

StandingState::~StandingState() {
}

void StandingState::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::A)) {
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
}

