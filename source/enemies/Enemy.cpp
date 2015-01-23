/*
 * =====================================================================================
 *
 *       Filename:  Enemy.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 21:38:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Enemy.hpp"
#include "Map.hpp"
#include "SoundEffect.hpp"

Enemy::Enemy(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction) : Enemy() {
	load(filename, x, y, width, height, direction);
}

void Enemy::load(const std::string &filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	Battler::load(filename, x, y, width, height, direction);
	
	m_destroyAnimation.addAnimation({0, 1, 0, 1, 0, 2, 3, 3, 2, 2, 3, 3, 2, 4, 4, 5, 5, 4, 6, 7}, 10);
}

void Enemy::reset(Map &map) {
	Battler::reset(map);
	
	m_destroyAnimation.resetAnimation(0);
	
	m_dead = false;
}

void Enemy::draw() {
	if(m_dead && !m_destroyAnimation.animationAtEnd(0)) {
		m_destroyAnimation.playAnimation(m_x - 8, m_y - 8, 0);
	}
}

void Enemy::mapBordersCollisions() {
	if(m_x + m_vx + m_hitbox.width > Map::currentMap->width() * 16
	|| m_x + m_vx < 0
	|| m_y + m_vy + m_hitbox.height > Map::currentMap->height() * 16
	|| m_y + m_vy < 0) {
		mapCollisionAction(m_vx, m_vy);
	}
}

void Enemy::checkDeath() {
	if(m_life == 0) {
		m_dead = true;
		
		SoundEffect::play("enemyDie");
		
		m_life = m_maxLife;
	}
}

