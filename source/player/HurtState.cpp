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
#include "HurtState.hpp"
#include "Sound.hpp"

HurtState::HurtState() {
	m_movement = new HurtMovement(&m_character);
	
	Sound::Effect::linkHurt.play();
}

HurtState::~HurtState() {
	delete m_movement;
}

void HurtState::update() {
	m_movement->update();
	
	if(m_movement->isFinished()) {
		setNextState(m_character.defaultState());
	}
}

void HurtState::render() {
	m_character.drawFrame(m_character.x(), m_character.y(), m_character.direction());
}

