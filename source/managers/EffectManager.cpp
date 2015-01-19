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
 *        Company:  
 *
 * =====================================================================================
 */
#include "TilesData.hpp"
#include "EffectManager.hpp"

Sprite EffectManager::grassEffect;
Sprite EffectManager::lowWaterEffect;

void EffectManager::init() {
	grassEffect.load("animations-grassEffect", 16, 16);
	
	lowWaterEffect.load("animations-lowWaterEffect", 16, 16);
	lowWaterEffect.addAnimation({0, 1, 2}, 100);
}

void EffectManager::drawEffects(const MapObject &object) {
	if(object.onTile(TilesData::TileType::LowGrassTile)) {
		EffectManager::grassEffect.drawFrame(object.x(), object.y(), 0);
	}
	
	if(object.onTile(TilesData::TileType::LowWaterTile)) {
		EffectManager::lowWaterEffect.playAnimation(object.x(), object.y() + 8, 0);
	}
}

