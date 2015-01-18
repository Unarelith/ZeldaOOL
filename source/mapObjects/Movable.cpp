/*
 * =====================================================================================
 *
 *       Filename:  Movable.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/01/2015 01:48:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "Movable.hpp"

Movable::Movable(const std::string &filename, u16 frameWidth, u16 frameHeight) : MapObject(filename, frameWidth, frameHeight) {
}

void Movable::update() {
	if(!m_movement) throw EXCEPTION("Trying to use undefined movement");
	
	m_movement->doMovement(*this);
	
	m_moving = (m_vx || m_vy) ? true : false;
	
	if(m_moving) {
		testCollisions();
		
		move(m_vx * m_speed, m_vy * m_speed);
		
		m_vx = 0;
		m_vy = 0;
	}
}

void Movable::draw() {
	if(m_moving) {
		playAnimation(m_x, m_y, m_direction);
	} else {
		drawFrame(m_x, m_y, m_direction);
	}
}

