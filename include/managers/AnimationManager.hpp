/*
 * =====================================================================================
 *
 *       Filename:  AnimationManager.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 23:11:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef ANIMATIONMANAGER_HPP_
#define ANIMATIONMANAGER_HPP_

#include <vector>

#include "Sprite.hpp"
#include "Vector2.hpp"

namespace AnimationManager {
	void init();
	
	void playAnimations();
	
	void addGrassDestroyAnimation(u16 tileX, u16 tileY);
	void addMonsterDestroyAnimation(s16 x, s16 y);
	
	extern Sprite grassDestroy;
	extern Sprite monsterDestroy;
	
	extern std::vector<std::pair<Sprite, Vector2i>> anims;
}

#endif // ANIMATIONMANAGER_HPP_
