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
#include "AnimationManager.hpp"
#include "Enemy.hpp"
#include "Map.hpp"
#include "Sound.hpp"

Enemy::Enemy() {
	m_battlerType = BattlerType::TypeEnemy;
	
	m_strength = 1;
	
	m_dead = false;
}

Enemy::Enemy(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	load(filename, x, y, width, height, direction);
}

Enemy::~Enemy() {
}

void Enemy::load(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	Battler::load(filename, x, y, width, height, direction);
}

void Enemy::mapBordersCollisions() {
	if(m_x + m_hitbox.width + m_vx > Map::currentMap->width() * 16
	|| m_x + m_vx < 0
	|| m_y + m_hitbox.height + m_vy > Map::currentMap->height() * 16
	|| m_y + m_vy < 0) {
		mapCollisionAction(m_vx, m_vy);
	}
}

void Enemy::checkDeath() {
	if(m_life == 0) {
		m_dead = true;
		
		AnimationManager::addMonsterDestroyAnimation(m_x, m_y);
		Sound::Effect::enemyDie.play();
		
		m_life = m_maxLife;
	}
}

