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
#include "GamePad.hpp"
#include "MovingState.hpp"
#include "StandingState.hpp"
#include "Weapon.hpp"

void MovingState::update() {
	if(!GamePad::isKeyPressed(GameKey::Left)
	&& !GamePad::isKeyPressed(GameKey::Right)
	&& !GamePad::isKeyPressed(GameKey::Up)
	&& !GamePad::isKeyPressed(GameKey::Down)) {
		setNextState<StandingState>();
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::A)
	&& m_character.inventory().weaponA() != nullptr) {
		m_character.inventory().weaponA()->updateOwnerNextState();
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::B)
	&& m_character.inventory().weaponB() != nullptr) {
		m_character.inventory().weaponB()->updateOwnerNextState();
	}
	
	m_character.updateMovement();
}

void MovingState::render() {
	m_character.playAnimation(m_character.x(), m_character.y(), m_character.direction());
}

