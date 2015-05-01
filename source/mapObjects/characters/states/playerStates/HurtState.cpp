/*
 * =====================================================================================
 *
 *       Filename:  HurtState.cpp
 *
 *    Description:  
 *
 *        Created:  09/10/2014 22:59:58
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "HurtMovement.hpp"
#include "HurtState.hpp"
#include "StandingState.hpp"

HurtState::HurtState(s16 vx, s16 vy, float speed) {
	AudioPlayer::playEffect("linkHurt");
	
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

