/*
 * =====================================================================================
 *
 *       Filename:  Octorok.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 21:39:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Octorok.hpp"

Octorok::Octorok() {
}

Octorok::Octorok(u16 x, u16 y, u8 direction) {
	load(x, y, direction);
}

Octorok::~Octorok() {
}

void Octorok::load(u16 x, u16 y, u8 direction) {
	Enemy::load("graphics/enemies/octorok.png", x, y, 16, 16, direction);
	
	addAnimation({4, 0}, 150);
	addAnimation({5, 1}, 150);
	addAnimation({6, 2}, 150);
	addAnimation({7, 3}, 150);
	
	m_state = State::Standing;
	
	m_movementCounter = 0;
	
	m_vx = 0;
	m_vy = 0;
}

void Octorok::update() {
	if(m_state == State::Standing) {
		m_timer.start();
		
		if(m_timer.time() > 1000) {
			m_vx = rand() % 3 - 1;
			if(m_vx == 0) m_vy = rand() % 3 - 1;
			
			if(m_vx < 0) m_direction = Direction::Left;
			if(m_vx > 0) m_direction = Direction::Right;
			if(m_vy < 0) m_direction = Direction::Up;
			if(m_vy > 0) m_direction = Direction::Down;
			
			if(m_vx != 0 || m_vy != 0) m_state = State::Moving;
		}
	}
	else if(m_state == State::Moving) {
		if(m_movementCounter < 16) {
			move(m_vx * 0.2f, m_vy * 0.2f);
			
			m_movementCounter += 0.2f;
		} else {
			m_timer.reset();
			
			m_vx = 0;
			m_vy = 0;
			
			m_movementCounter = 0;
			
			m_state = State::Standing;
		}
	}
}

void Octorok::draw() {
	if(m_state == State::Standing) {
		drawFrame(m_x, m_y - 16, m_direction);
	}
	else if(m_state == State::Moving) {
		playAnimation(m_x, m_y - 16, m_direction);
	}
}

