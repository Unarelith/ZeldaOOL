/*
 * =====================================================================================
 *
 *       Filename:  Octorok.cpp
 *
 *    Description:  
 *
 *        Created:  07/10/2014 21:39:15
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "HurtMovement.hpp"
#include "Octorok.hpp"
#include "OctorokMovement.hpp"

Octorok::Octorok(u16 x, u16 y, u8 direction) {
	load(x, y, direction);
}

void Octorok::load(u16 x, u16 y, u8 direction) {
	Enemy::load("enemies-octorok", x, y, 16, 16, direction);
	
	addAnimation({4, 0}, 150);
	addAnimation({5, 1}, 150);
	addAnimation({6, 2}, 150);
	addAnimation({7, 3}, 150);
	
	setMovement<OctorokMovement>();
	
	addCollisionHandler(std::bind(&Character::mapCollisions, this));
	addCollisionHandler(std::bind(&Enemy::mapBordersCollisions, this));
	
	m_maxLife = 2;
	m_life = m_maxLife;
}

void Octorok::update() {
	if(!m_dead) {
		Battler::update();
		Movable::update();
	}
}

void Octorok::draw() {
	Enemy::draw();
	
	if(m_dead) return;
	
	if(m_hurt) {
		drawFrame(m_x, m_y, m_direction);
	}
	else if(m_moving && !m_blocked) {
		playAnimation(m_x, m_y, m_direction);
	}
	else {
		drawFrame(m_x, m_y, m_lastFrameDisplayed);
	}
}

void Octorok::hurtAction(s16 vx, s16 vy) {
	AudioPlayer::playEffect("enemyHit");
	
	setMovement<HurtMovement>(vx, vy, 0.8);
}

