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

HurtMovement::HurtMovement(Character *character) : Movement(character) {
	m_movementCounter = 0;
	
}

HurtMovement::~HurtMovement() {
}

void HurtMovement::update() {
	if(m_movementCounter < 16) {
		m_character->mapCollisions();
		
		m_character->move(m_character->vx() * 0.4, m_character->vy() * 0.4);
		
		m_movementCounter += 0.4;
	} else {
		m_isFinished = true;
	}
}

