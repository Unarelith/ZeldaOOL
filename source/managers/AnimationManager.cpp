/*
 * =====================================================================================
 *
 *       Filename:  AnimationManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/09/2014 22:12:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "AnimationManager.hpp"

Sprite AnimationManager::grassDestroy;

std::vector<std::pair<Sprite, sf::Vector2i>> AnimationManager::anims;

void AnimationManager::init() {
	grassDestroy.load("graphics/animations/grassDestroy.png", 32, 32);
	grassDestroy.addAnimation({0, 1, 2, 3, 4, 5}, 50);
}

void AnimationManager::playAnimations() {
	for(s16 i = 0 ; i < (s16)anims.size() ; i++) {
		if(!anims[i].first.animationAtEnd(0)) {
			anims[i].first.playAnimation(anims[i].second.x, anims[i].second.y, 0);
		} else {
			anims.erase(anims.begin() + i--);
		}
	}
}

void AnimationManager::addGrassDestroyAnimation(u16 tileX, u16 tileY) {
	anims.push_back(std::make_pair(Sprite(grassDestroy), sf::Vector2i(tileX * 16 - 8, tileY * 16 - 8)));
}

