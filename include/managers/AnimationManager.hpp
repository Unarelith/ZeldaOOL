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

#include <SFML/Graphics.hpp>

#include "Sprite.hpp"

namespace AnimationManager {
	void init();
	
	void playAnimations();
	
	void addGrassDestroyAnimation(u16 tileX, u16 tileY);
	
	extern Sprite grassDestroy;
	
	extern std::vector<std::pair<Sprite, sf::Vector2i>> anims;
}

#endif // ANIMATIONMANAGER_HPP_
