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
#include "CharacterManager.hpp"
#include "HeartCollectable.hpp"
#include "Sound.hpp"

HeartCollectable::HeartCollectable(float x, float y) : Collectable(x, y, "graphics/collectables/heart.png") {
	
}

HeartCollectable::~HeartCollectable() {
}

void HeartCollectable::action() {
	Sound::Effect::getHeart.play();
	
	CharacterManager::player.inventory().addHearts(1);
}

