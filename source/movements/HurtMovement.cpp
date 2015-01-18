/*
 * =====================================================================================
 *
 *       Filename:  HurtMovement.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  13/10/2014 00:52:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "HurtMovement.hpp"

HurtMovement::HurtMovement(Character *character, float speed) {
	m_character = character;
	
	m_speed = speed;
}

void HurtMovement::reset() {
	m_isFinished = false;
	
	m_movementCounter = 0;
}

void HurtMovement::update() {
	if(m_movementCounter < 16) {
		m_character->mapCollisions();
		
		m_character->move(m_character->vx() * m_speed, m_character->vy() * m_speed);
		
		m_movementCounter += m_speed;
	} else {
		m_isFinished = true;
	}
}

