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
}

StandingState::~StandingState() {
}

void StandingState::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::A)
	&& m_character.inventory().weaponA() != nullptr) {
		setNextState(m_character.inventory().weaponA()->playerStateTransition());
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::B)
	&& m_character.inventory().weaponB() != nullptr) {
		setNextState(m_character.inventory().weaponB()->playerStateTransition());
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Left)
	|| Keyboard::isKeyPressed(Keyboard::Right)
	|| Keyboard::isKeyPressed(Keyboard::Up)
	|| Keyboard::isKeyPressed(Keyboard::Down)) {
		setNextState([]{ return new MovingState; });
	}
}

void StandingState::render() {
	m_character.drawFrame(m_character.x(), m_character.y(), m_character.direction());
}

