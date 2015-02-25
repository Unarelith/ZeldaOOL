/*
 * =====================================================================================
 *
 *       Filename:  SpriteComponent.hpp
 *
 *    Description:  
 *
 *        Created:  14/02/2015 17:41:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include "Sprite.hpp"

class SpriteComponent {
	public:
		SpriteComponent(const std::string &textureName, u16 frameWidth, u16 frameHeight)
			: sprite(textureName, frameWidth, frameHeight) {}
		
		Sprite sprite;
		
		u16 animID = 0;
		
		bool isAnimated = false;
};

#endif // SPRITECOMPONENT_HPP_
