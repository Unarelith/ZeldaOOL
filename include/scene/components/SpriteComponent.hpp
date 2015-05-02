/*
 * =====================================================================================
 *
 *       Filename:  SpriteComponent.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 12:46:29
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
		
		bool isAnimated = false;
		
		u16 animID = 0;
		u16 frameID = 0;
		
		Sprite sprite;
};

#endif // SPRITECOMPONENT_HPP_
