/*
 * =====================================================================================
 *
 *       Filename:  Movable.cpp
 *
 *    Description:  
 *
 *        Created:  18/01/2015 01:48:03
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "Exception.hpp"
#include "Movable.hpp"

Movable::Movable(const std::string &textureName, float x, float y, u16 frameWidth, u16 frameHeight) {
	MapObject::load(textureName, x, y, frameWidth, frameHeight);
}

void Movable::load(const std::string &textureName, float x, float y, u16 frameWidth, u16 frameHeight) {
	MapObject::load(textureName, x, y, frameWidth, frameHeight);
}

void Movable::updateMovement() {
	if(!m_movement) throw EXCEPTION("Trying to update undefined movement");
	
	m_movement->process(*this);
	
	m_blocked = false;
	
	testCollisions();
	
	m_moving = (m_vx || m_vy) ? true : false;
	
	move(m_vx * m_speed, m_vy * m_speed);
	
	setVelocity(0, 0);
}

void Movable::draw() {
	if(m_moving) {
		playAnimation(m_x, m_y, m_direction);
	} else {
		drawFrame(m_x, m_y, m_direction);
	}
	
	MapObject::draw();
}

