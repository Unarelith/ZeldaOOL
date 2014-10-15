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
#include "HurtState.hpp"
#include "Keyboard.hpp"
#include "MovingState.hpp"
#include "StandingState.hpp"
#include "Weapon.hpp"

StandingState::StandingState() {
}

StandingState::~StandingState() {
}

void StandingState::update() {
	if(Keyboard::isKeyPressedOnce(Keyboard::A)) {
		m_player.setVelocity(-1, -1);
		
		m_player.stateManager().setNextState(new HurtState);
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::A)
	&& m_player.inventory().weaponA() != nullptr) {
		m_player.stateManager().setNextState(m_player.inventory().weaponA()->playerState());
	}
	
	if(Keyboard::isKeyPressedOnce(Keyboard::B)
	&& m_player.inventory().weaponB() != nullptr) {
		m_player.stateManager().setNextState(m_player.inventory().weaponB()->playerState());
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Left)
	|| Keyboard::isKeyPressed(Keyboard::Right)
	|| Keyboard::isKeyPressed(Keyboard::Up)
	|| Keyboard::isKeyPressed(Keyboard::Down)) {
		m_player.stateManager().setNextState(new MovingState);
	}
}

void StandingState::draw() {
	m_player.drawFrame(m_player.x(), m_player.y(), m_player.direction());
}

