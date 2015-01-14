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

#include <map>

#include "Sprite.hpp"
#include "Vector2.hpp"

class AnimationManager {
	public:
		static void init();
		
		static void playAnimations();
		
		static void addGrassDestroyAnimation(u16 tileX, u16 tileY);
		static void addMonsterDestroyAnimation(s16 x, s16 y);
		
		static Sprite &getSprite(const std::string &name) { return sprites[name]; }
		
	private:
		static std::vector<std::pair<Sprite, Vector2i>> animations;
		
		static std::map<std::string, Sprite> sprites;
};

#endif // ANIMATIONMANAGER_HPP_
