/*
 * =====================================================================================
 *
 *       Filename:  HeartCollectable.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 17:19:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "Player.hpp"
#include "HeartCollectable.hpp"
#include "SoundEffect.hpp"

HeartCollectable::HeartCollectable(float x, float y) {
	Collectable::load("collectables-heart", x, y);
}

void HeartCollectable::action() {
	SoundEffect::play("getHeart");
	
	Player::player.addHearts(1);
}

