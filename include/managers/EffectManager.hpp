/*
 * =====================================================================================
 *
 *       Filename:  EffectManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/08/2014 20:07:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef EFFECTMANAGER_HPP_
#define EFFECTMANAGER_HPP_

#include "Sprite.hpp"
#include "Entity.hpp"

namespace EffectManager {
	void init();
	
	void drawEffects(Entity *e);
	
	extern Sprite grassEffect;
	extern Sprite lowWaterEffect;
}

#endif // EFFECTMANAGER_HPP_
