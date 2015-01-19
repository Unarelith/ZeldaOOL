/*
 * =====================================================================================
 *
 *       Filename:  AnimationManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:11:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "AnimationManager.hpp"

std::vector<std::pair<Sprite, Vector2i>> AnimationManager::animations;
std::map<std::string, Sprite> AnimationManager::sprites;

void AnimationManager::init() {
	sprites.emplace("grassDestroy", Sprite("animations-grassDestroy", 32, 32));
	sprites["grassDestroy"].addAnimation({0, 1, 2, 3, 4, 5}, 50);
	
	sprites.emplace("monsterDestroy", Sprite("animations-monsterDestroy", 32, 32));
	sprites["monsterDestroy"].addAnimation({0, 1, 0, 1, 0, 2, 3, 3, 2, 2, 3, 3, 2, 4, 4, 5, 5, 4, 6, 7}, 10);
}

void AnimationManager::playAnimations() {
	for(s16 i = 0 ; i < (s16)animations.size() ; i++) {
		if(!animations[i].first.animationAtEnd(0)) {
			animations[i].first.playAnimation(animations[i].second.x, animations[i].second.y, 0);
		} else {
			animations.erase(animations.begin() + i--);
		}
	}
}

void AnimationManager::addGrassDestroyAnimation(u16 tileX, u16 tileY) {
	animations.emplace_back(sprites["grassDestroy"], Vector2i(tileX * 16 - 8, tileY * 16 - 8));
}

void AnimationManager::addMonsterDestroyAnimation(s16 x, s16 y) {
	animations.emplace_back(sprites["monsterDestroy"], Vector2i(x - 8, y - 8));
}

