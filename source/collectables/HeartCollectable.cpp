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
#include "AudioPlayer.hpp"
#include "CharacterManager.hpp"
#include "HeartCollectable.hpp"

HeartCollectable::HeartCollectable(float x, float y) : Collectable(x, y, "collectables-heart") {
	
}

HeartCollectable::~HeartCollectable() {
}

void HeartCollectable::action() {
	AudioPlayer::playEffect("getHeart");
	
	CharacterManager::player.addHearts(1);
}

