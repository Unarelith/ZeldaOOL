/*
 * =====================================================================================
 *
 *       Filename:  AnimatedMap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 14:24:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "AnimatedMap.hpp"

AnimatedMap::AnimatedMap() {
}

AnimatedMap::AnimatedMap(std::string filename, std::string tilesetName) : TileMap(filename, tilesetName) {
}

AnimatedMap::~AnimatedMap() {
}

void AnimatedMap::updateTile(u16 tileX, u16 tileY) {
	TileMap::updateTile(tileX, tileY);
	
	for(auto &it : m_tileset->anims()) {
		for(auto &n : it.frames) {
			if(getTile(tileX, tileY) == n) {
				m_animatedTiles.push_back(AnimatedTile(tileX, tileY, n + 1 % it.frames.size(), it));
			}
		}
	}
}

void AnimatedMap::update() {
	for(auto &it : m_animatedTiles) {
		if(!it.timer.isStarted()) {
			it.timer.start();
		}
		
		if(it.timer.time() >= it.anim.delay) {
			setTile(it.tileX, it.tileY, it.anim.frames[it.nextFrame % it.anim.frames.size()]);
			it.nextFrame++;
			it.timer.reset();
			it.timer.start();
		}
	}
}

