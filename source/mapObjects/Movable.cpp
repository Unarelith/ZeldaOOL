/*
 * =====================================================================================
 *
 *       Filename:  Movable.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 17:28:43
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Movable.hpp"

Movable::Movable() {
	
}

Movable::Movable(std::string filename, u16 frameWidth, u16 frameHeight, Movement *movement) {
	load(filename, frameWidth, frameHeight, movement);
}

Movable::~Movable() {
}

void Movable::load(std::string filename, u16 frameWidth, u16 frameHeight, Movement *movement) {
	Sprite::load(filename, frameWidth, frameHeight);
	
	m_vx = 0;
	m_vy = 0;
	
	m_direction = Direction::Down;
	m_speed = 0.4f;
	m_moving = false;
	
	m_blocked = false;
	
	m_movement = std::unique_ptr<Movement>(movement);
}

void Movable::move() {
	m_movement->doMovement(*this);
	
	m_moving = (m_vx || m_vy) ? true : false;
	
	for(auto &it : m_collisionHandlers) {
		it();
	}
	
	sf::Transformable::move(m_vx * m_speed, m_vy * m_speed);
	
	m_vx = 0;
	m_vy = 0;
}

void Movable::draw() {
	if(m_moving) {
		playAnimation(m_direction);
	} else {
		drawFrame(m_direction);
	}
}

