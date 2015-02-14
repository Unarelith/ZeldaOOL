/*
 * =====================================================================================
 *
 *       Filename:  SpriteComponent.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 17:41:36
 *       Compiler:  gcc
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include "Sprite.hpp"

class SpriteComponent {
	public:
		SpriteComponent(const std::string &resourceName, u16 frameWidth, u16 frameHeight)
			: sprite(resourceName, frameWidth, frameHeight) {}
		
		Sprite sprite;
		
		u16 animID = 0;
		
		bool isAnimated = false;
};

#endif // SPRITECOMPONENT_HPP_
