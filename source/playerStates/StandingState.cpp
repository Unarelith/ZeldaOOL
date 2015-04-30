/*
 * =====================================================================================
 *
 *       Filename:  StandingState.cpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:24:54
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "MovingState.hpp"
#include "StandingState.hpp"
#include "Weapon.hpp"

void StandingState::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::A)
	&& m_character.inventory().weaponA() != nullptr) {
		m_character.inventory().weaponA()->updateOwnerNextState();
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::B)
	&& m_character.inventory().weaponB() != nullptr) {
		m_character.inventory().weaponB()->updateOwnerNextState();
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Left)
	|| Keyboard::isKeyPressed(Keyboard::Right)
	|| Keyboard::isKeyPressed(Keyboard::Up)
	|| Keyboard::isKeyPressed(Keyboard::Down)) {
		setNextState<MovingState>();
	}
}

void StandingState::render() {
	m_character.drawFrame(m_character.x(), m_character.y(), m_character.direction());
}

