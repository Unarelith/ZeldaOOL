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
#include "MovingState.hpp"
#include "StandingState.hpp"
#include "Weapon.hpp"

StandingState::StandingState() {
	m_stateType = StateType::TypeStanding;
	m_nextStateType = StateType::TypeStanding;
}

StandingState::~StandingState() {
}

void StandingState::update() {
	if(Keyboard::isKeyPressed(Keyboard::A)
	&& m_player.inventory()->weaponA() != nullptr) {
		m_nextStateType = m_player.inventory()->weaponA()->playerState();
	}
	
	if(Keyboard::isKeyPressed(Keyboard::B)
	&& m_player.inventory()->weaponB() != nullptr) {
		m_nextStateType = m_player.inventory()->weaponB()->playerState();
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

