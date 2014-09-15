/*
 * =====================================================================================
 *
 *       Filename:  EffectManager.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:59:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "TilesData.hpp"
#include "EffectManager.hpp"

Sprite EffectManager::grassEffect;
Sprite EffectManager::lowWaterEffect;

void EffectManager::init() {
	grassEffect.load("graphics/animations/grassEffect.png", 16, 16);
	
	lowWaterEffect.load("graphics/animations/lowWaterEffect.png", 16, 16);
	lowWaterEffect.addAnimation({0, 1, 2}, 100);
}

void EffectManager::drawEffects(Entity *e) {
	if(e->onTile(TilesData::TileType::LowGrassTile)) {
		EffectManager::grassEffect.drawFrame(e->x(), e->y(), 0);
	}
	
	if(e->onTile(TilesData::TileType::LowWaterTile)) {
		EffectManager::lowWaterEffect.playAnimation(e->x(), e->y() + 8, 0);
	}
}

