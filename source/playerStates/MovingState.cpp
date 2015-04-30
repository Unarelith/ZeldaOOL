/*
 * =====================================================================================
 *
 *       Filename:  MovingState.cpp
 *
 *    Description:  
 *
 *        Created:  15/09/2014 22:25:07
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Keyboard.hpp"
#include "MovingState.hpp"
#include "StandingState.hpp"
#include "Weapon.hpp"

void MovingState::update() {
	if(!Keyboard::isKeyPressed(Keyboard::Left)
	&& !Keyboard::isKeyPressed(Keyboard::Right)
	&& !Keyboard::isKeyPressed(Keyboard::Up)
	&& !Keyboard::isKeyPressed(Keyboard::Down)) {
		setNextState<StandingState>();
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::A)
	&& m_character.inventory().weaponA() != nullptr) {
		m_character.inventory().weaponA()->updateOwnerNextState();
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::B)
	&& m_character.inventory().weaponB() != nullptr) {
		m_character.inventory().weaponB()->updateOwnerNextState();
	}
	
	m_character.updateMovement();
}

void MovingState::render() {
	m_character.playAnimation(m_character.x(), m_character.y(), m_character.direction());
}

