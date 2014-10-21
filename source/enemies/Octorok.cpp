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
#include "MapManager.hpp"
#include "Octorok.hpp"

Octorok::Octorok() {
}

Octorok::Octorok(u16 x, u16 y, u8 direction) {
	load(x, y, direction);
}

Octorok::~Octorok() {
	delete m_hurtMovement;
}

void Octorok::load(u16 x, u16 y, u8 direction) {
	Enemy::load("graphics/enemies/octorok.png", x, y, 16, 16, direction);
	
	addAnimation({4, 0}, 150);
	addAnimation({5, 1}, 150);
	addAnimation({6, 2}, 150);
	addAnimation({7, 3}, 150);
	
	m_hurtMovement = new HurtMovement(this);
	
	reset();
}

void Octorok::reset() {
	m_state = State::Standing;
	
	m_timer.reset();
	
	m_movementCounter = 0;
	
	m_randomMaxMovement = (rand() % 5) * 8;
	
	stopAnimation(m_direction);
}

void Octorok::update() {
	Battler::update();
	
	if(m_state == State::Standing) {
		m_timer.start();
		
		if(m_timer.time() > 1000) {
			m_vx = rand() % 3 - 1;
			m_vy = rand() % 3 - 1;
			
			if(m_vx != 0 && m_vy != 0) {
				if(rand() % 2 == 0) {
					m_vx = 0;
				} else {
					m_vy = 0;
				}
			}
			
			mapCollisions();
			
			updateDirection();
			
			if(m_vx != 0 || m_vy != 0) m_state = State::Moving;
		}
	}
	else if(m_state == State::Moving) {
		if(m_movementCounter < 16 + m_randomMaxMovement) {
			if(m_x + m_hitbox.width + m_vx > MapManager::currentMap->width() * 16
			|| m_x + m_vx < 0
			|| m_y + m_hitbox.height + m_vy > MapManager::currentMap->height() * 16
			|| m_y + m_vy < 0) {
				mapCollisionAction(m_vx, m_vy);
			}
			
			mapCollisions();
			
			move(m_vx * 0.3f, m_vy * 0.3f);
			
			m_movementCounter += 0.3f;
		} else {
			reset();
		}
	}
	else if(m_state == State::Hurt) {
		m_hurtMovement->update();
		
		if(m_hurtMovement->isFinished()) {
			m_state = State::Standing;
		}
	}
}

void Octorok::draw() {
	if(m_state == State::Standing) {
		drawFrame(m_x, m_y, m_lastFrameDisplayed);
	}
	else if(m_state == State::Moving) {
		playAnimation(m_x, m_y, m_direction);
	}
	else if(m_state == State::Hurt) {
		drawFrame(m_x, m_y, m_direction);
	}
}

void Octorok::mapCollisionAction(float vx, float vy) {
	if(vx != 0) {
		m_vy = rand() % 3 - 1;
		if(m_vy == 0) m_vx = -m_vx;
		else m_vx = 0;
	}
	else if(vy != 0) {
		m_vx = rand() % 3 - 1;
		if(m_vx == 0) m_vy = -m_vy;
		else m_vy = 0;
	}
	
	updateDirection();
}

