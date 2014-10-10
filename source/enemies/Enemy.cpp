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

Enemy::Enemy() {
	
}

Enemy::Enemy(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	load(filename, x, y, width, height, direction);
}

Enemy::~Enemy() {
}

void Enemy::load(std::string filename, u16 x, u16 y, u16 width, u16 height, u8 direction) {
	Battler::load(filename, x, y, width, height, direction);
}

