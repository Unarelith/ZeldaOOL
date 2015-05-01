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
#include "GamePad.hpp"
#include "MovingState.hpp"
#include "StandingState.hpp"
#include "Weapon.hpp"

void StandingState::update() {
	if(GamePad::isKeyPressedOnce(GameKey::A)
	&& m_character.inventory().weaponA() != nullptr) {
		m_character.inventory().weaponA()->updateOwnerNextState();
	}
	
	if(GamePad::isKeyPressedOnce(GameKey::B)
	&& m_character.inventory().weaponB() != nullptr) {
		m_character.inventory().weaponB()->updateOwnerNextState();
	}
	
	if(GamePad::isKeyPressed(GameKey::Left)
	|| GamePad::isKeyPressed(GameKey::Right)
	|| GamePad::isKeyPressed(GameKey::Up)
	|| GamePad::isKeyPressed(GameKey::Down)) {
		setNextState<MovingState>();
	}
}

void StandingState::render() {
	m_character.drawFrame(m_character.x(), m_character.y(), m_character.direction());
}

