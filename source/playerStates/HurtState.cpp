/*
 * =====================================================================================
 *
 *       Filename:  HurtState.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/10/2014 22:59:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "HurtMovement.hpp"
#include "HurtState.hpp"
#include "StandingState.hpp"
#include "SoundEffect.hpp"

HurtState::HurtState(s16 vx, s16 vy, float speed) {
	SoundEffect::play("linkHurt");
	
	m_character.setMovement<HurtMovement>(vx, vy, speed);
}

void HurtState::update() {
	m_character.updateMovement();
	m_character.update(false);
	
	if(!m_character.hurt()) {
		setNextState<StandingState>();
	}
}

void HurtState::render() {
	m_character.drawFrame(m_character.x(), m_character.y(), m_character.direction());
}

