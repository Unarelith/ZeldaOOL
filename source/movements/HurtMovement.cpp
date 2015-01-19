/*
 * =====================================================================================
 *
 *       Filename:  HurtMovement.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/01/2015 18:56:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Enemy.hpp"
#include "HurtMovement.hpp"
#include "Movable.hpp"

HurtMovement::HurtMovement(s16 vx, s16 vy, float speed) {
	m_vx = vx;
	m_vy = vy;
	
	m_speed = speed;
}

void HurtMovement::doMovement(Movable &movable) {
	movable.setSpeed(m_speed);
	
	if(m_movementCounter < 16) {
		movable.setVelocity(m_vx, m_vy);
		
		m_movementCounter += m_speed;
	} else {
		// FIXME: TO REMOVE LATER
		if(movable.checkType<Enemy>()) {
			Enemy &enemy = static_cast<Enemy&>(movable);
			enemy.checkDeath();
		}
		
		movable.resetMovement();
	}
}

