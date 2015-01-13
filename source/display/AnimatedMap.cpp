/*
 * =====================================================================================
 *
 *       Filename:  AnimatedMap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/12/2014 13:48:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#include "AnimatedMap.hpp"

AnimatedMap::AnimatedMap(AnimatedMap &&animatedMap) : TileMap(std::move(animatedMap)),
	m_animatedTiles(std::move(animatedMap.m_animatedTiles)){
}

AnimatedMap::AnimatedMap(Tileset &tileset, u16 width, u16 height) {
	load(tileset, width, height);
}

void AnimatedMap::load(Tileset &tileset, u16 width, u16 height) {
	TileMap::load(tileset, width, height);
}

void AnimatedMap::updateTile(u16 tileX, u16 tileY, u16 id) {
	TileMap::updateTile(tileX, tileY, id);
	
	for(auto &it : m_tileset->anims()) {
		for(auto &n : it.frames) {
			if(id == n) {
				m_animatedTiles.push_back(AnimatedTile(tileX, tileY, n + 1 % it.frames.size(), it));
			}
		}
	}
}

void AnimatedMap::animateTiles() {
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

