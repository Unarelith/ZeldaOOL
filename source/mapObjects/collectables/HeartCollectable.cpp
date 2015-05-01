/*
 * =====================================================================================
 *
 *       Filename:  HeartCollectable.cpp
 *
 *    Description:  
 *
 *        Created:  07/10/2014 17:19:34
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#include "AudioPlayer.hpp"
#include "HeartCollectable.hpp"
#include "Player.hpp"

HeartCollectable::HeartCollectable(float x, float y) {
	Collectable::load("collectables-heart", x, y);
}

void HeartCollectable::action() {
	AudioPlayer::playEffect("getHeart");
	
	Player::player.addHearts(1);
}

