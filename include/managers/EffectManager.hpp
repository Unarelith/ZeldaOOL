/*
 * =====================================================================================
 *
 *       Filename:  EffectManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 22:58:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef EFFECTMANAGER_HPP_
#define EFFECTMANAGER_HPP_

#include "Sprite.hpp"
#include "MapObject.hpp"

namespace EffectManager {
	void init();
	
	void drawEffects(const MapObject &object);
	
	extern Sprite grassEffect;
	extern Sprite lowWaterEffect;
}

#endif // EFFECTMANAGER_HPP_
